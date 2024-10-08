#ifndef BLOBPTR_H
#define BLOBPTR_H

#include <vector>
#include <string>
#include <memory>
#include <cstddef>
#include <stdexcept>
#include <iostream>

template <typename T> class Blob;
template <typename T> class BlobPtr;

template <typename T> bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator<(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> std::ptrdiff_t operator-(const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T>
class BlobPtr {
	friend bool operator==<T>(const BlobPtr<T> &, const BlobPtr<T> &);
	friend bool operator< <T>(const BlobPtr<T> &, const BlobPtr<T> &);
	friend std::ptrdiff_t operator-<T>(const BlobPtr<T> &, const BlobPtr<T> &);
public:
	BlobPtr();
	BlobPtr(Blob<T> &, std::size_t = 0);

	T &operator*() const;

	BlobPtr &operator+=(std::size_t);
	BlobPtr &operator-=(std::size_t);

	BlobPtr &operator++();		// prefix
	BlobPtr &operator--();
	BlobPtr operator++(int);	// postfix
	BlobPtr operator--(int);

private:
	std::shared_ptr<std::vector<T>>	check(std::size_t, const std::string &) const;

	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};

template <typename T>
BlobPtr<T>::BlobPtr()
try : curr(0) {}
catch (const std::exception &err) {
	std::cerr << err.what() << std::endl;
}

template <typename T>
BlobPtr<T>::BlobPtr(Blob<T> &a, std::size_t sz)
try : wptr(a.data), curr(sz)  {}
catch (const std::exception &err) {
	std::cerr << err.what() << std::endl;
}
// Dereference
template <typename T>
T &BlobPtr<T>::operator*() const {
	std::shared_ptr<std::vector<T>> p = check(curr, "dereference past end");
	return (*p)[curr];
}
// Compound addition assignment
template <typename T>
BlobPtr<T> &BlobPtr<T>::operator+=(std::size_t n) {
	curr += n;
	check(curr - 1, "increment past end of BlobPtr");
	return *this;
}
// Compound subtraction assignment
template <typename T>
BlobPtr<T> &BlobPtr<T>::operator-=(std::size_t n) {
	curr -= n;
	check(curr, "decrement past beginning of BlobPtr");
	return *this;
}
// Prefix increment
template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++() {
	check(curr, "increment past end of BlobPtr");
	++curr;
	return *this;
}
// Prefix decrement
template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--() {
	check(--curr, "decrement past beginning of BlobPtr");
	return *this;
}
// Postfix increment
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
	BlobPtr old = *this;
	++*this;
	return old;
}
// Postfix decrement
template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
	BlobPtr old = *this;
	--*this;
	return old;
}

template <typename T>
std::shared_ptr<std::vector<T>> 
BlobPtr<T>::check(std::size_t i, const std::string &msg) const {
	std::shared_ptr<std::vector<T>> ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound BlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

// Equality
template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return (lhs.wptr.lock() == rhs.wptr.lock())
			&& (lhs.curr == rhs.curr);
}
// Inequality
template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return !(lhs == rhs);
}
// Less-than
template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock())
		throw std::runtime_error("comparing two BlobPtrs that don't point to the same object");
	return lhs.curr < rhs.curr;
}
// Greater-than
template <typename T>
bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return rhs < lhs;
}
// Less-than or equal
template <typename T>
bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return !(lhs > rhs);
}
// Greater-than or equal
template <typename T>
bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return !(lhs < rhs);
}
// Addition
template <typename T>
BlobPtr<T> operator+(const BlobPtr<T> &p, std::size_t n) {
	BlobPtr<T> ret = p;
	ret += n;
	return ret;
}
// Subtraction
template <typename T>
BlobPtr<T> operator-(const BlobPtr<T> &p, std::size_t n) {
	BlobPtr<T> ret = p;
	ret -= n;
	return ret;
}
// Subtraction
template <typename T>
std::ptrdiff_t operator-(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock())
		throw std::runtime_error("the two BlobPtrs don't point to the same object");
	return lhs.curr - rhs.curr;
}

#endif
