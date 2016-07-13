/*
 * main.cpp
 *
 *  Created on: 2016/07/07
 *      Author: tmakimoto
 */

#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

#include "cfddef.h"
#include "quantity.h"
#include "flux.h"

int main(int argc, char** argv) {

	const std::size_t N = 101;
	typedef std::vector<cfd::Quantity> QVector;
	QVector Q(N);

	const cfd::Quantity LHS_Initial_q(1.0, 0.0, 10.0 / (cfd::CFD::Gamma - 1.0));
	const cfd::Quantity RHS_Initial_q(0.1, 0.0, 1.0 / (cfd::CFD::Gamma - 1.0));

	const std::size_t N_2 = N / 2;

	std::fill(Q.begin(), Q.begin() + N_2, LHS_Initial_q);
	std::fill(Q.begin() + N_2, Q.end(), RHS_Initial_q);

	cfd::flux F;

	const double dt = 0.002;

	cfd::Quantity dQ;
	std::size_t i = 0;
	do {
		dQ = cfd::Quantity::Zero();
		std::vector<cfd::Quantity> newQ(Q.begin(), Q.end());
		for (std::size_t i = 1; i < Q.size() - 1; ++i) {
			const Eigen::RowVector3d Er = 0.5
					* (F(Q[i]) + F(Q[i + 1]) - (Q[i + 1] - Q[i]) / dt);
			const Eigen::RowVector3d El = 0.5
					* (F(Q[i - 1]) + F(Q[i]) - (Q[i] - Q[i - 1]) / dt);
			newQ[i] = Q[i] - dt * (Er - El);
			dQ += newQ[i] - Q[i];
		}
		newQ[0] = newQ[1];
		newQ[newQ.size() - 1] = newQ[newQ.size() - 2];

		std::copy(newQ.begin(), newQ.end(), Q.begin());
		++i;
	} while (/*dQ.norm() >= 1.0E-7*/i < 100);

	for (std::size_t i = 0; i < Q.size(); ++i) {
		std::cout << i << " " << Q[i] << std::endl;
	}
//	std::cout << "Finish this program." << std::endl;

	exit(EXIT_SUCCESS);
}
