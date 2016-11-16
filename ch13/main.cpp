/*
 * main.cpp
 *
 *  Created on: 16-Nov-2016
 *      Author: adil
 */

#include "Grad.cpp"
#include "student_info.cpp"
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const Core& c1, const Core& c2)
{
	return c1.name() < c2.name();
}

bool compare_grades(const Core& c1, const Core& c2)
{
	return c1.grade() < c2.grade();
}

int main()
{
//    Grad g(cin);
//    Grad g2(cin);
//
//    Core c(cin);
//	Core c2(cin);
//
//	compare(g, g2);
//	compare(c, c2);
//	compare(c, g);

	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	while(record.read(cin)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	//alphabetize the records
	sort(students.begin(), students.end(), Student_info::compare);

	//write the names and grades
	for(vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].name()
				<< string(maxlen + 1 - students[i].name().size(), ' ');

		try {
			double final_grade = students[i].grade(); //Core::grade
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		} catch(domain_error e) {
			cout << e.what() << endl;
		}
	}

	return 0;
}
