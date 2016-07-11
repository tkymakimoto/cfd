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

int main(int argc, char** argv) {

	const std::size_t N = 1000;
	typedef std::vector<cfd::Quantity> QVector;
	QVector Q(N);

	const cfd::Quantity LHS_Initial_q(1.0, 0.0, 0.0);
	const cfd::Quantity RHS_Initial_q(1.0, 0.0, 1.0 / cfd::CFD::Gamma);

	const std::size_t N_2 = N / 2;

	std::fill(Q.begin(), Q.begin() + N_2, LHS_Initial_q);
	std::fill(Q.begin() + N_2, Q.end(), RHS_Initial_q);

	for (std::size_t i = 0; i < Q.size(); ++i) {
		std::cout << i << Q[i] << std::endl;
	}

	exit(EXIT_SUCCESS);
}
