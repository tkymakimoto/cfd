/*
 * main.cpp
 *
 *  Created on: 2016/07/07
 *      Author: tmakimoto
 */

#include <cstdlib>

#include "quantity.h"

int main(int argc, char** argv) {

	std::size_t N = 1000;
	std::vector<cfd::Quantity> Q(N);

	const cfd::Quantity LHS_Initial_q(1.0, 0.0, 0.0);
	const cfd::Quantity RHS_Initial_q(1.0, 0.0, 0.0);

	exit(EXIT_SUCCESS);
}
