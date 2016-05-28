/*
 * Student_info.h
 *
 *  Created on: May 28, 2016
 *      Author: adil
 */

#ifndef CH4_STUDENT_INFO_H_
#define CH4_STUDENT_INFO_H_


#include <iostream>
#include <string>
#include <vector>

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif /* CH4_STUDENT_INFO_H_ */
