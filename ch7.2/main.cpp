/*
 * main.cpp
 *
 *  Created on: 15-Sep-2016
 *      Author: adil
 */

#include <iostream>
#include <map>

using namespace std;

int main()
{
	string s;
	map<string, int> counters; //Store each word and associated counter

	cout << "Press Ctrl+D to exit" << endl;

	// How does cin know to split a string by space?
	while(cin >> s) {
		++counters[s];
	}

	for(map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it) {
		// When we dereference a map iterator, we get a type `pair<const string, int>`. `pair` stores the key in `first` and value in `second`
		cout << it->first << "\t" << it->second << endl;
	}

	return 0;
}


