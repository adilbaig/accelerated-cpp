#include <stdio>
#include <vector>

/**
 * This template generates a median from any vector.
 * Note: template instantiation is done at the linking stage, which is why you might get
 * wierd linker errors if you get the types wrong.
 *
 * pg 141
 *
 * the template header `template <class T>` tells the compiler that we are defining a template function
 */

template <class T>
T median(vector<T> v)
{
	/**
	 * This tells the compiler that `vector<T>::size_type` is the name of the type we want
	 * vec_sz is its variable
	 */
	typedef typename vector<T>::size_type vec_sz;

	vec_sz size = v.size();
	if(size == 0)
		throw new domain_error("median of an empty vector");

	// sort requires a random-access iterator
	sort(v.begin(), v.end());
	vec_sz mid = size/2;

	return size % 2 == 0 ? (v[mid] + v[mid - 1]) /2 : v[mid];
}
