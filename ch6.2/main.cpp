#include <vector>
#include <algorithm>
#include "../ch4/Student_info.h"

bool did_all_hw(const Student_info& s)
{
    return find(s.homework.begin(), s.homework.end(), 0) == s.homework.end();
}

double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);

    return median(grades);
}

double grade_aux(const Student_info& s)
{
    try {
        return grade(s);
    } catch(domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

void write_analysis(ostream& out, const string& name,
                    double analysis(const vector<Student_info>&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt
                    )
{
    out << name << ": median(did) = " << analysis(did) << ", median(didnt) = " << analysis(didnt) << endl;
}

double average(const vector<double>& v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const vector<double>& v)
{
    return grade(s.midterm, s.final, average(v));
}

double average_analysis(const vector<Student_info>& students)
{
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), average_grade);
    return median(grades);
}

bool pgrade(const Student_info& student)
{
    return !fgrade(student);
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    /**
     * Stable partition keeps the order of the original items intact, after pushing failing
     * grades to the end
     */
    vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
    vector<Student_info> fail(iter, students.end());
    students.erase(iter, students.end());

    return fail;
}

int main()
{
    vector<Student_info> did, didnt;

    Student_info student;
    while(read(cin, student)) {
        if(did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }

    if(did.empty()) {
        cout << "No student did all the homework" << endl;
        return 1;
    }
    if(didnt.empty()) {
        cout << "Every student did all the homework" << endl;
        return 1;
    }

    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);

    return 0;
}