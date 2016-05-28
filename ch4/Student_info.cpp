/*
 * From pg 69
 *
 * Note that we include the header file, the file contains both definitions and
 * declarations. This redundancy is harmless, and is actually a good idea. It
 * gives the compiler the opportunity to check for consistency between the
 * declarations and definitions.
 *
 */

#include "Student_info.h"

using std::istream;
using std::vector;
using std::cout;
using std::endl;

bool compare(const Student_info& x, const Student_info& y) {
	return x.name < y.name;
}

istream& read(istream& is, Student_info& s) {
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}

istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		//get rid of previous content
		hw.clear();

		// read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);

		// clear the stream so that input will work for the next student
		in.clear();
	}

	return in;
}
