/*
 * Str.cpp
 *
 *  Created on: 12-Nov-2016
 *      Author: adil
 */

#include <algorithm>
#include <string>
#include "../ch11/Vec.cpp"

using namespace std;

class Str {

	friend std::istream& operator>>(std::istream&, Str&);
	friend std::ostream& operator<<(std::ostream&, const Str&);

public:

	typedef Vec<char>::size_type size_type;

	Str(); // default ctor. Creates an empty Str

	Str(size_type n, char c) :
			data(n, c) {
	}

	Str(const char* cp) {
		std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
	}

	template<class In> Str(In b, In e) {
		std::copy(b, e, std::back_inserter(data));
	}

	char& operator[](size_type i) {
		return data[i];
	}
	const char& operator[](size_type i) const {
		return data[i];
	}

	size_type size() const {
		return data.size();
	}

	Str& operator+=(const Str& s) {
		std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));

		return *this;
	}

	ostream& operator<<(ostream& os, const Str& s) {
		for (Str::size_type i = 0; i != s.size(); ++i)
			os << s[i];

		return os;
	}

	/*
	 * Conversion operators
	 * For a discussion on design and pitfalls of conversion operators, see Pg 222
	 *
	 * operator double() const; //This converts this object to a double
	 *
	 * ```
	 * double d = Str("Adil");
	 * ```
	 *
	 */

	operator void*() const {
		return (void*) data.begin();
	}

private:
	Vec<char> data;
};

Str operator+(const Str& s, const Str& t) {
	Str r = s;
	r += t;
	return r;
}

istream& operator>>(istream& is, Str& s) {
	s.data.clear();

	char c;
	while (is.get(c) && isspace(c))
		//skip initial whitespace
		;

	if (is) { //if there is still input
		do
			s.data.push_back(c);
		while (is.get(c) && !isspace(c));

		// if we read a space using is.get(c), put it back
		if (is)
			is.unget();
	}

	return is;
}

