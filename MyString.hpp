/**
 *  Deniz Erisgen ©
 */
#ifndef MYSTRING_HPP
#define MYSTRING_HPP
#include "MyDict.hpp"

#include <cstring>
#include <iostream>

using namespace std;

class MyString : public string {
public:
	MyString() = default;
	void lower();
	void removePunctuation();
	explicit operator unsigned() const;
};

template<typename M>
class DuplicateError : public logic_error {
public:
	explicit DuplicateError(M some) : logic_error(some) {};
	friend ostream &operator<<(ostream &os, const DuplicateError<M> &error) {
		os << error.what();
		return os;
	}
};


#endif  // MYSTRING_HPP
