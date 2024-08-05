#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <cstddef>
#include <string>
#include <memory>
#include <vector>
#include <stdexcept>

#include "StrBlob.h"

class StrBlobPtr {
	friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

	friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

	friend StrBlobPtr operator+(const StrBlobPtr &, std::size_t);
	friend StrBlobPtr operator-(const StrBlobPtr &, std::size_t);
	friend std::ptrdiff_t operator-(const StrBlobPtr &, const StrBlobPtr &);
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}

	std::string &operator[](std::size_t);
	const std::string &operator[](std::size_t) const;

	StrBlobPtr &operator++();	// prefix
	StrBlobPtr &operator--();
	StrBlobPtr operator++(int);	// postfix
	StrBlobPtr operator--(int);

	std::string &deref() const;
	StrBlobPtr &incr();
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

bool operator==(const StrBlobPtr &, const StrBlobPtr &);
bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

bool operator<(const StrBlobPtr &, const StrBlobPtr &);
bool operator>(const StrBlobPtr &, const StrBlobPtr &);
bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

StrBlobPtr operator+(const StrBlobPtr &, std::size_t);
StrBlobPtr operator-(const StrBlobPtr &, std::size_t);
std::ptrdiff_t operator-(const StrBlobPtr &, const StrBlobPtr &);



#endif
