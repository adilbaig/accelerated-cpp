//
// Created by adil on 10/9/16.
//

#include <string>
#include <cctype>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

/**
 * Function to split a sentence into words
 *
 * @param s
 * @return
 */
vector<string> split(const string& s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i =0;

    while(i != s.size()) {

        while(i != s.size() && isspace(s[i]))
            ++i;

        string_size  j = i;
        while(j != s.size() && !isspace(s[j]))
            ++j;

        // We've found a string
        if(i != j) {
            ret.push_back(s.substr(i, j - 1));
            i = j;
        }
    }

    return ret;
}

int main()
{
    string s;

    while(getline(cin, s)) {
        vector<string> v = split(s);

        for(vector<string>::size_type i = 0; i != v.size(); ++i)
            cout << v[i] << endl;
    }

    s.clear();
    while(cin >> s) {
        cout << s << endl;
    }

    return 0;
}