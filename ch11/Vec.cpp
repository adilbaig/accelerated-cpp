/*
 * Vec.cpp
 *
 *  Created on: 29-Oct-2016
 *      Author: adil
 */

#include <stddef.h> // For size_t
#include <cstddef> //For std::ptrdiff_t

/**
 * Why <memory> and not <memory.h>?
 *
 * <string> is the C++ standard library string header file containing std::string
 * and its friends. <string.h> is a different header, from the C standard library,
 * which has functions for manipulating C strings (null-terminated strings) and other
 * related functions.
 *
 * The two are entirely different and unrelated. In C++ (as in C), a header file can
 * have any extension. The C++ standard library headers have no extension; the C standard library
 * headers have a .h extension.  .hpp or .hxx are also common.
 */
#include <memory>

using namespace std;

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
	 *
	 * IMPORTANT : http://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-in-c-mean
	 * If a ctor does not have explicit, it can be used for auto-type-conversion when a param is called.
	 *
	 * ```
	 * You have a MyString(int size) class with a constructor that constructs a
	 * string of the given size. You have a function print(const MyString&),
	 * and you call it with print(3). You expect it to print "3",
	 * but it prints an empty string of length 3 instead.
	 * ```
	 * DAMN!
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
	void push_back(const T& val) {
		if(avail == limit) //grow if space is needed ..
			grow();

		unchecked_append(val); // and push the value
	}

	void clear()
	{
		uncreate();
	}

private:
	iterator data;
	iterator avail; // point to one past the last constructed element.
	iterator limit;

	// Allocator
	std::allocator<T> alloc;

	void create() {
		data = avail = limit = 0;
	}

	void create(size_type n, const T& val) {
		data = alloc.allocate(n);
		limit = avail = data + n;
		uninitialized_fill(data, limit, val);
	}

	void create(const_iterator i, const_iterator j) {
		data = alloc.allocate(j - i);
		limit = avail = uninitialized_copy(i, j, data);
	}

	//Destroy elements in the array and free memory
	void uncreate() {
		if (data) {
			//destroy, in reverse order, the elements that were constructed
			iterator it = avail;
			while (it != data)
				alloc.destroy(--it);

			//return all the space that was allocated
			alloc.deallocate(data, limit - data);
		}

		//reset pointers to indidate the Vec is empty again
		data = limit = avail = 0;
	}

	//support functions for push_back
	void grow() {
		//when growing, allocate twice as much space as is currently in use
		size_type new_size = max(2 * (limit - data), ptrdiff_t(1));

		//allocate new space and copy existing elements into the new space
		iterator new_data = alloc.allocate(new_size);
		iterator new_avail = uninitialized_copy(data, avail, new_data);

		//return the old space
		uncreate();

		// reset pointers to point to the newly allocated space
		data = new_data;
		avail = new_avail;
		limit = data + new_size;
	}

	// assumes avail points at allocated but uninitialized data
	void unchecked_append(const T& val) {
		alloc.construct(avail++, val);
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

