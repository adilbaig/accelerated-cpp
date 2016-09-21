//
// Created by adil on 21/9/16.
//

#include "Student_info.h"
#include "../ch4/Student_info.cpp"
#include "../ch4/grade.h"

/**
 * IN the CPP file, we define `using namespace`. In the H file, we use full namespaces
 */
using namespace std;

/**
 * This is the definition of the Student_info::read method
 *
 * @param in
 * @return
 */
istream& Student_info::read(istream& in)
{
    in >> name() >> midterm >> final;
    read_hw(in, homework);
    return in;
}

/**
 * Student_info::grade
 * The const means this method will not write to any member of the Struct.
 * Also, this method may only be called by a `const` reference to Student_info
 *
 * Q: What about writing to private members?
 *
 * @return
 */
double Student_info::grade() const
{
    return ::grade(midterm, final, homework);
}

/**
 * This is the definition of the default constructor
 *
 * `: midterm(0), final(0)` Initilize these members to explicitly be zero. Wierd!?!
 */
Student_info::Student_info(): midterm(0), final(0) {}