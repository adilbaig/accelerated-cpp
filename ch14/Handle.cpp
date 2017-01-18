/*
 * Handle.cpp
 *
 *  Created on: 21-Nov-2016
 *      Author: adil
 */

template<class T> class Handle {

public:
	Handle() :
			p(0) {
	}
	Handle(const Handle& s) :
			p(0) {
		if (s.p)
			p = s.p->clone();
	}
	Handle(T* t) :
			p(t) {
		cout << "Running this";
	}

	~Handle() {
		cout << "Destroy";
		delete p;
	}

	Handle& operator=(const Handle&);

	operator bool() const {
		return p;
	}
	T& operator*() const;
	T* operator->() const;

private:
	T* p;
};

template<class T>
Handle<T>& Handle<T>::operator=(const Handle& rhs) {
	if (&rhs != this) {
		delete p;
		p = rhs.p ? rhs.p->clone() : 0;
	}

	return *this;
}

/**
 * This is the * unary operator
 * Returns a reference to the original object such that
 *
 * *handle == T
 */
template<class T>
T& Handle<T>::operator*() const {
	if (p)
		return *p;

	throw runtime_error("Unbound Handle");
}

/**
 * Returns a pointer to the original object such that
 *
 * handle->y == (handle.operator->())->y
 */
template<class T>
T* Handle<T>::operator->() const {
	if (p)
		return p;

	throw runtime_error("Unbound Handle");
}

template<class T>
bool Handle<T>::operator bool() {
	return (p != 0);
}
