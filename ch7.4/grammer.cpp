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

vector<string> gen_sentence(const Grammar& g)
{
	vector<string> ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}

bool bracketed(const string& s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

int nrand(int n)
{
	if(n <= 0 || n > RAND_MAX)
		throw domain_error("Argument to nrand is out of range");

	const int bucket_size = RAND_MAX / n;
	int r;

	do r = rand() / bucket_size;
	while(r >= n);

	return r;
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
	if(!bracketed(word))
		ret.push_back(word);
	else {

		//locate the rule that corresponds to word
		Grammar::const_iterator it = g.find(word);
		if(it == g.end())
			throw logic_error("empty rule");

		// fetch a list of possible rules ..
		const RuleCollection& c = it->second;

		// .. from which we select one at random
		const Rule& r = c[nrand(c.size()];

		// recursively expand the selected rule
		for(Rule::const_iterator i = r.begin(); i != r.end(); ++i)
			gen_aux(g, *i, ret);
	}
}

int main()
{
	//gen the sentence
	vector<string> sentence = gen_sentence(read_grammar(cin));

	//write the first word, if any
	vector<string>::const_iterator it = sentence.begin();
	if(!sentence.empty()) {
		cout << " " << *it;
		++it;
	}

	//write the rest of the words
	while(it != sentence.end()) {
		cout << " " << *it;
		++it;
	}

	cout << endl;
	return 0;
}
