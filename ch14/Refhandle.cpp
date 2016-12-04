/*
 * Refhandle.cpp
 *
 *  Created on: 04-Dec-2016
 *      Author: adil
 */

#include <exception>

using namespace std;

template<class T>
class Ref_handle {
public:
    Ref_handle() : p(0), refptr(new std::size_t(1)) {}
    Ref_handle(T* t) : p(t), refptr(new std::size_t(1)) {}
    Ref_handle(const Ref_handle& h) : p(h.p), refptr(h.refptr) {
    	++*refptr;
    }
    Ref_handle& operator=(const Ref_handle&);
    ~Ref_handle() {
    	if (--*refptr == 0) {
    		delete refptr;
    		delete p;
    	}
    }

    T& operator*() const
    {
    	if (p)
    		return *p;

    	throw runtime_error("Unbound Ref_handle");
    }

    T* operator->() const
    {
    	if (p)
    		return p;

    	throw runtime_error("Unbound Ref_handle");
    }

    operator bool() const {
    	return p;
    }

private:
    T* p;
    std::size_t* refptr;
};

template <class T>
Ref handle<T>& Ref_handle<T>::operator=(const Ref_handle& rhs)
{
	++*rhs.refptr;
	if(--*refptr == 0) {
		delete refptr;
		delete p;
	}

	//copy in values from the rhs
	refptr = rhs.refptr;
	p = rhs.p;
	return *this;
}
