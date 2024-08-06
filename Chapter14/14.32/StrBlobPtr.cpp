#include "StrBlobPtr.h"

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const {
	std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

std::string &StrBlobPtr::deref() const {
	std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return lhs.wptr.lock() == rhs.wptr.lock() &&
			lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock())
		throw std::runtime_error("comparing two StrBlobPtrs that don't point to the same object");
	return lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return rhs < lhs;
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !(lhs > rhs);
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !(lhs < rhs);

}

std::string &StrBlobPtr::operator[](std::size_t n) {
	std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
	return (*p)[n];
}

const std::string &StrBlobPtr::operator[](std::size_t n) const {
	std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
	return (*p)[n];
}

// prefix operators
StrBlobPtr &StrBlobPtr::operator++() {
	check(curr++, "increment past end of StrBlobPtr");
	return *this;
}
StrBlobPtr &StrBlobPtr::operator--() {
	check(--curr, "decrement past begin of StrBlobPtr");
	return *this;
}

// postfix operator
StrBlobPtr StrBlobPtr::operator++(int) {
	StrBlobPtr ret = *this;
	++*this;
	return ret;
}
StrBlobPtr StrBlobPtr::operator--(int) {
	StrBlobPtr ret = *this;
	--*this;
	return ret;
}

StrBlobPtr operator+(const StrBlobPtr &p, std::size_t n) {
	StrBlobPtr ret = p;
	ret.curr += n;
	ret.check(ret.curr - 1, "incrementing past end of StrBlobPtr");
	return ret;
}
StrBlobPtr operator-(const StrBlobPtr &p, std::size_t n) {
	StrBlobPtr ret = p;
	ret.curr -= n;
	ret.check(ret.curr, "decrement past begin of StrBlobPtr");
	return ret;
}
std::ptrdiff_t operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock())
		throw std::runtime_error("StrBlobPtrs don't refer to the same object");
	std::ptrdiff_t ret = lhs.curr;
	ret -= rhs.curr;
	return ret;
}

std::string &StrBlobPtr::operator*() const {
	std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
	return (*p)[curr];
}
std::string *StrBlobPtr::operator->() const {
	return &this->operator*();
}
