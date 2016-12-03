/*
 * main.cpp
 *
 *  Created on: 03-Dec-2016
 *      Author: adil
 */

#include <iostream>
#include "../ch11/Vec.cpp"
#include "Handle.cpp"

using namespace std;

int main(int argc, const char * argv[])
{
//    int i;
//    for(i = 0; i < argc; i++) {
//        cout << "Argument " << i << " = " << argv[i] << "\n";
//    }

	Vec<int>* c = new Vec<int>(5, 10);
//	Vec<int> stackObj(5, 10);

	Vec<int>::const_iterator i;
	for(i = (*c).begin(); i < (*c).end(); i++) {
		cout << *i << "\n";
	}

	cout << "Address is " << &c << "\n";

	Handle< Vec<int> > handle(c); // Handle works when object is allocated on the heap
    return 0;
}


