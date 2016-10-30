/*
 * main.cpp
 *
 *  Created on: 30-Oct-2016
 *      Author: adil
 */

#include "Vec.cpp"
#include <iostream>

using namespace std;

int main()
{
	Vec<int> vector = Vec<int>(10, 5);
	vector.push_back(159);

	Vec<int>::const_iterator it;
	int index = 0;
	for(it = vector.begin(); it != vector.end(); ++it) {
		cout << index++ << ") " << *it << endl;
	}

	cout << "Size is " << vector.size() << endl;

	return 0;
}


