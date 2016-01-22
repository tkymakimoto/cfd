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

typedef double cfd_float;

/**
 * Ratio of specific heats
 */
const cfd_float Gamma = 1.4;

}  // namespace cfd

#endif /* CFDDEF_H_ */
