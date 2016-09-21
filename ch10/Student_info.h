//
// Created by adil on 21/9/16.
//

#include <vector>
#include <string>
#include <istream>

class Student_info {

public:
    Student_info();
    Student_info(std::istream&);

    std::string name() const { return n; };
    bool valid() const { return !homework.empty(); }
    std::istream& read(std::istream&);
    double grade() const;

private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
