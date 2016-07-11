/*
 * cfddef.h
 *
 *  Created on: 2015/01/29
 *      Author: makitaku
 */

#ifndef CFDDEF_H_
#define CFDDEF_H_

//#if __GNUC__
//#   if __cplusplus < 201103L
//#       include <bits/c++0x_warning.h>
//#   endif
//#endif

namespace cfd {

struct CFD {
	enum {
		Rho, Momentum, Energy, Size
	};

	/**
	 * Ratio of specific heats.
	 */
	static const double Gamma = 1.4;

	/**
	 * Gas constant.
	 */
	static const double GasConstant = 287.3;
};

}  // namespace cfd

#endif /* CFDDEF_H_ */
