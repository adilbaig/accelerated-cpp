#include <iostream>
#include <vector>
#include <list>
#include "../ch4/Student_info.h"
#include "../ch4/grade.h"

using std::vector;
using std::iostream;
using std::list;

bool fgrade(const Student_info& s);

/*
 * This is an old implementation that does not use iterators
 */
/*vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::size_type i = 0;

	while(i != students.size()) {
		if (fgrade(students[i])) {
			fail.push_back(students[i]);
			students.erase(studens.begin() + i);
		} else
			++i;
	}

	return fail;
}*/

/**
 * This uses iterators to create a fail vector
 *
 * @param students
 * @return vector<Student_info>
 */
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();

    while(iter != students.end()) {
        if(fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }

    return fail;
}

/**
 * Same as above, but with a list. Pg.85
 *
 * @param students
 * @return
 */
list<Student_info> extract_fails(list<Student_info>& students)
{
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

    while(iter != students.end()) {
        if(fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }

    return fail;
}

bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}