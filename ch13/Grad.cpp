/*
 * Grad.cpp
 *
 *  Created on: 16-Nov-2016
 *      Author: adil
 */

#include "Grad.hpp"
#include "Core.cpp"

using namespace std;

//both ctors implicitly use Core::Core() to initialize the base part
Grad::Grad(): thesis(0) {}
Grad::Grad(istream& is) {
	read(is);
}

// This doesn't need to be virtual, because Core::clone is
Grad* Grad::clone() const {
	return new Grad(*this);
}

istream& Grad::read(istream& in)
{
    read_common(in);
    in >> thesis;
    read_hw(in, homework);
    return in;
}

double Grad::grade() const
{
    return min(Core::grade(), thesis);
}
