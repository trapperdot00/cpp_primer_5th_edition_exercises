#include "ConstStrBlobPtr.h"

std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
	std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

const std::string &ConstStrBlobPtr::deref() const {
	std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
	return (*p)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	return lhs.wptr.lock() == rhs.wptr.lock() &&
			lhs.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	return !(lhs == rhs);
}

bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock())
		throw std::runtime_error("comparing two ConstStrBlobPtrs that don't point to the same object");
	return lhs.curr < rhs.curr;
}

bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	return rhs < lhs;
}

bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	return !(lhs > rhs);
}

bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	return !(lhs < rhs);
}

std::string &ConstStrBlobPtr::operator[](std::size_t n) {
	std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
	return (*p)[n];
}

const std::string &ConstStrBlobPtr::operator[](std::size_t n) const {
	std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
	return (*p)[n];
}

// prefix operators
ConstStrBlobPtr &ConstStrBlobPtr::operator++() {
	check(curr++, "increment past end of ConstStrBlobPtr");
	return *this;
}
ConstStrBlobPtr &ConstStrBlobPtr::operator--() {
	check(--curr, "decrement past begin of ConstStrBlobPtr");
	return *this;
}

// postfix operators
ConstStrBlobPtr ConstStrBlobPtr::operator++(int) {
	ConstStrBlobPtr ret = *this;
	++*this;
	return ret;
}
ConstStrBlobPtr ConstStrBlobPtr::operator--(int) {
	ConstStrBlobPtr ret = *this;
	--*this;
	return ret;
}

ConstStrBlobPtr operator+(const ConstStrBlobPtr &p, std::size_t n) {
	ConstStrBlobPtr ret = p;
	ret.curr += n;
	ret.check(ret.curr - 1, "incrementing past end of ConstStrBlobPtr");
	return ret;
}
ConstStrBlobPtr operator-(const ConstStrBlobPtr &p, std::size_t n) {
	ConstStrBlobPtr ret = p;
	ret.curr -= n;
	ret.check(ret.curr, "decrement past begin of ConstStrBlobPtr");
	return ret;
}
std::ptrdiff_t operator-(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock())
		throw std::runtime_error("ConstStrBlobPtrs don't refer to the same object");
	std::ptrdiff_t ret = lhs.curr;
	ret -= rhs.curr;
	return ret;
}
