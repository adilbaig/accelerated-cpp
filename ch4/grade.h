/*
 * grade.h
 *
 *  Created on: May 28, 2016
 *      Author: adil
 */

#ifndef CH4_GRADE_H_
#define CH4_GRADE_H_

#include <vector>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

#endif /* CH4_GRADE_H_ */
