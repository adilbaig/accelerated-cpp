/*
 * Vec.cpp
 *
 *  Created on: 29-Oct-2016
 *      Author: adil
 */

#include <stddef.h> // For size_t
#include <cstddef> //For std::ptrdiff_t

template<class T> class Vec {

public:
	/**
	 * We provide typedefs to hide the implementation details of our class.
	 * This is similar to the container definitions in std C++
	 */
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef T& reference;
	typedef const T& const_reference;

	/*
	 * A standard implicit ctor
	 */
	Vec() {
		create();
	}

	/**
	 * An explicit ctor.
	 * Needs to be called with (). Ex: Vec(5, 50);
	 */
	explicit Vec(size_type n, const T& val = T()) {
		create(n, val);
	}

	/**
	 * A copy constructor
	 * This is a special ctor called when we want to make a copy of Vec.
	 * It requires a reference type. Further, copying an object should not changed the
	 * original, hence it should be `const` as well.
	 *
	 * Pg. 195
	 */
	Vec(const Vec& vector) {
		create(vector.begin(), vector.end());
	}

	/**
	 * dtor
	 */
	~Vec() {
		uncreate();
	}

	/**
	 * Number of elements in the vector;
	 */
	size_type size() const {
		return limit - data;
	}

	/**
	 * Overload for `vec[i]` and `const vec[i]`
	 */
	T& operator[](size_type i) {
		return data[i];
	}
	const T& operator[](size_type i) const {
		return data[i];
	}

	/**
	 * Overload for the assignment operator (=)
	 * This is called when an object is assigned to a variable.
	 * An assignment ALWAYS destroys the variable and replaces it with a value
	 * An initialization only creates a new value.
	 * See pg.199 for difference between initialization and assignment
	 *
	 * This is a declaration, definition is below.
	 */
	Vec& operator=(const Vec&);

	/**
	 * Return begin and end iterators, just like std::vector
	 */
	iterator begin() {
		return data;
	}
	const_iterator begin() const {
		return data;
	}

	iterator end() {
		return limit;
	}
	const_iterator end() const {
		return limit;
	}

	/**
	 * Push a value into the end of the vector
	 */
	void push_back(const T& val)
	{
//		if(avail == limit) //grow if space is needed ..
//			grow();
//
//		unchecked_append(val); // and push the value
	}

private:
	iterator data;
	iterator avail; // point to one past the last constructed element.
	iterator limit;

	void create() {
	}
	void create(size_type n, const T& val) {
	}
};


/**
 * Note that the parameter is of type :
 *
 * const Vec& rhs
 *
 * instead of
 *
 * const Vec<T>& rhs
 *
 * Inside a template, any access to Vec will assume to be Vec<T>,
 * the compiler automatically makes the second type for us from the first type, so
 * we don't need write the full form explicitly.
 *
 */
template<class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) {

	//check for self assignment
	if (&rhs != this) {
		uncreate();
		create(rhs.begin(), rhs.end());
	}

	return *this;
}

void uncreate() {
}

