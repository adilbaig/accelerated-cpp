/*
 * Core.hpp
 *
 *  Created on: 16-Nov-2016
 *      Author: adil
 */
#ifndef CH13_CORE_HPP_
#define CH13_CORE_HPP_

#include <iostream>
#include <string>
#include <vector>

class Core {
	friend class Student_info;

public:
    Core();
    Core(std::istream&);
    std::string name() const;
    std::istream& read(std::istream&);
    virtual double grade() const;

protected:
    std::istream& read_common(std::istream&);
    double midterm, final;
    std::vector<double> homework;
    virtual Core* clone() const;

private:
    std::string n;
};

#endif /* CH13_GRAD_HPP_ */
