/*
 * flux.h
 *
 *  Created on: 2016/07/13
 *      Author: Takuya
 */

#ifndef SRC_FLUX_H_
#define SRC_FLUX_H_

#include "quantity.h"

namespace cfd {

class flux {
public:
	flux() {
	}

	~flux() {
	}

	Eigen::RowVector3d operator()(const Quantity& Q) const {
		const double u = Q[CFD::Momentum] / Q[CFD::Rho];
		const double p = (CFD::Gamma - 1.0)
				* (Q[CFD::Energy] - 0.5 * Q[CFD::Momentum] * u);
		return Eigen::RowVector3d(Q[CFD::Momentum], Q[CFD::Momentum] * u + p,
				(Q[CFD::Energy] + p) * u);
	}
};

}  // namespace cfd

#endif /* SRC_FLUX_H_ */
