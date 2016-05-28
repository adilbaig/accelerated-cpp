#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::vector;
using std::string;
using std::setprecision;
using std::streamsize;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	cout << "Insert data in the form: NAME MIDTERM FINAL HOMEWORK1 .. HOMEWORKN" << endl ;
	cout << "Press CTRL + D twice to compute result" << endl ;

	while(read(cin, record)) {
		// find length of the longest name
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	//alphabetize student records
	sort(students.begin(), students.end(), compare);

	// write the names and grades
	for(vector<Student_info>::size_type i = 0; i != students.size(); ++i) {

		//write the name, padded on the right to maxlen + 1 chars
		cout << students[i].name
				<< string(maxlen + 1 - students[i].name.size(), ' ');

		// compute and write the grade
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();

			cout << setprecision(3)
					<< final_grade
					<< setprecision(prec);
		} catch (domain_error e) {
			cout << e.what();
		}

		cout << endl;
	}

	return 0;
}
