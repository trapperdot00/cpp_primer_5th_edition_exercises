#ifndef CONSTSTRBLOBPTR_H
#define CONSTSTRBLOBPTR_H

#include <cstddef>
#include <string>
#include <memory>
#include <vector>
#include <stdexcept>

#include "StrBlob.h"

class ConstStrBlobPtr {
	friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

	friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

	friend ConstStrBlobPtr operator+(const ConstStrBlobPtr &, std::size_t);
	friend ConstStrBlobPtr operator-(const ConstStrBlobPtr &, std::size_t);
	friend std::ptrdiff_t operator-(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
public:
	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}

	ConstStrBlobPtr &operator++();	// prefix
	ConstStrBlobPtr &operator--();
	ConstStrBlobPtr operator++(int);	// postfix
	ConstStrBlobPtr operator--(int);

	std::string &operator[](std::size_t);
	const std::string &operator[](std::size_t) const;

	const std::string &deref() const;
	ConstStrBlobPtr &incr();
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

ConstStrBlobPtr operator+(const ConstStrBlobPtr &, std::size_t);
ConstStrBlobPtr operator-(const ConstStrBlobPtr &, std::size_t);
std::ptrdiff_t operator-(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
#endif
