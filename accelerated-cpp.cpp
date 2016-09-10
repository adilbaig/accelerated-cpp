//============================================================================
// Name        : accelerated-cpp.cpp
// Author      : Adil Baig
// Version     :
// Copyright   : Copyleft
// Description : Accelerated C++
//============================================================================

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::domain_error;

double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if(size == 0)
		throw std::domain_error("Median of an empty vector!");

	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? vec[mid] + vec[mid-1] / 2
						 : vec[mid];
}

/*
 * 'const vector<double>&' is a 'reference to const vector of double'
 */
double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0) {
		throw domain_error("Student has done no homework!");
	}

	return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

int main(void) {

	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	//Notice how the two lines of string are automatically concatenated
	cout << "Ent`er all your homework grades, "
			"followed by end-of-file: ";

	vector<double> homework;
	double x;

	while (cin >> x)
		homework.push_back(x);

	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if (size == 0) {
		cout << endl << "You must enter your grades.  "
				"Please try again." << endl;
		return 1;
	}

	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
			<< grade(midterm, final, homework)
			<< setprecision(prec) << endl;

	cout << "Goodbye";
	return EXIT_SUCCESS;
}

