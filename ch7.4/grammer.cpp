#include <vector>
#include <iostream>
#include <map>

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> RuleCollection;
typedef map<string, RuleCollection> Grammar;

Grammar read_grammer(istream& in)
{
	Grammer ret;
	string line;

	while(getline(in, line)) {
		vector<string> entry = split(line);

		if(!entry.empty())
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
	}

	return ret;
}
