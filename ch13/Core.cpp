/*
 * Core.cpp
 *
 *  Created on: 16-Nov-2016
 *      Author: adil
 */

#include "Core.hpp"

using namespace std;

Core::Core(): midterm(0), final(0){}
Core::Core(istream& is) {
	read(is);
}

Core* Core::clone() const {
	return new Core(*this);
}


string Core::name() const {
    return n;
}

double Core::grade() const {
    return ::grade(midterm, final, homework);
}

istream& Core::read_common(istream& in)
{
    in >> n >> midterm >> final;
    return in;
}

istream& Core::read(istream& in)
{
    read_common(in);
    read_hw(in, homework);
    return in;
}
