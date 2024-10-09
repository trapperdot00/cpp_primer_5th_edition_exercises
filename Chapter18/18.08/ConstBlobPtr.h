#ifndef CONSTBLOBPTR_H
#define CONSTBLOBPTR_H

#include <vector>
#include <string>
#include <memory>
#include <cstddef>
#include <stdexcept>
#include <iostream>

template <typename T> class Blob;
template <typename T> class ConstBlobPtr;

template <typename T> bool operator==(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template <typename T> bool operator<(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template <typename T> std::ptrdiff_t operator-(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);

template <typename T>
class ConstBlobPtr {
	friend bool operator==<T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
	friend bool operator< <T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
	friend std::ptrdiff_t operator-<T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
public:
	ConstBlobPtr() noexcept;
	ConstBlobPtr(const Blob<T> &, std::size_t = 0) noexcept;

	const T &operator*() const;

	ConstBlobPtr &operator+=(std::size_t);
	ConstBlobPtr &operator-=(std::size_t);

	ConstBlobPtr &operator++();		// prefix
	ConstBlobPtr &operator--();
	ConstBlobPtr operator++(int);	// postfix
	ConstBlobPtr operator--(int);

private:
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
	
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};

template <typename T>
ConstBlobPtr<T>::ConstBlobPtr() noexcept
try : curr(0) {}
catch (const std::exception &err) {
	std::cerr << err.what() << std::endl;
}

template <typename T>
ConstBlobPtr<T>::ConstBlobPtr(const Blob<T> &a, std::size_t sz) noexcept
try : wptr(a.data), curr(sz) {}
catch (const std::exception &err) {
	std::cerr << err.what() << std::endl;
}
// Dereference
template <typename T>
const T &ConstBlobPtr<T>::operator*() const {
	std::shared_ptr<std::vector<T>> p = check(curr, "dereference past end");
	return (*p)[curr];
}
// Compound addition assignment
template <typename T>
ConstBlobPtr<T> &ConstBlobPtr<T>::operator+=(std::size_t n) {
	curr += n;
	check(curr - 1, "increment past end of ConstBlobPtr");
	return *this;
}
// Compound subtraction assignment
template <typename T>
ConstBlobPtr<T> &ConstBlobPtr<T>::operator-=(std::size_t n) {
	curr -= n;
	check(curr, "decrement past beginning of ConstBlobPtr");
	return *this;
}
// Prefix increment
template <typename T>
ConstBlobPtr<T> &ConstBlobPtr<T>::operator++() {
	check(curr, "increment past end of ConstBlobPtr");
	++curr;
	return *this;
}
// Prefix decrement
template <typename T>
ConstBlobPtr<T> &ConstBlobPtr<T>::operator--() {
	check(--curr, "decrement past beginning of ConstBlobPtr");
	return *this;
}
// Postfix increment
template <typename T>
ConstBlobPtr<T> ConstBlobPtr<T>::operator++(int) {
	ConstBlobPtr old = *this;
	++*this;
	return old;
}
// Postfix decrement
template <typename T>
ConstBlobPtr<T> ConstBlobPtr<T>::operator--(int) {
	ConstBlobPtr old = *this;
	--*this;
	return old;
}

template <typename T>
std::shared_ptr<std::vector<T>>
ConstBlobPtr<T>::check(std::size_t i, const std::string &msg) const {
	std::shared_ptr<std::vector<T>> ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound ConstBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

// Equality
template <typename T>
bool operator==(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
	return (lhs.wptr.lock() == rhs.wptr.lock())
		    && (lhs.curr == rhs.curr);
}
// Inequality
template <typename T>
bool operator!=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
	return !(lhs == rhs);
}
// Less-than
template <typename T>
bool operator<(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock())
		throw std::runtime_error("comparing two ConstBlobPtrs that don't point to the same object");
	return lhs.curr < rhs.curr;
}
// Greater-than
template <typename T>
bool operator>(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
	return rhs < lhs;
}
// Less-than or equal
template <typename T>
bool operator<=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
	return !(lhs > rhs);
}
// Greater-than or equal
template <typename T>
bool operator>=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
	return !(lhs < rhs);
}
// Addition
template <typename T>
ConstBlobPtr<T> operator+(const ConstBlobPtr<T> &p, const std::size_t n) {
	ConstBlobPtr<T> ret = p;
	ret += n;
	return ret;
}
// Subtraction
template <typename T>
ConstBlobPtr<T> operator-(const ConstBlobPtr<T> &p, const std::size_t n) {
	ConstBlobPtr<T> ret = p;
	ret -= n;
	return ret;
}
// Subtraction
template <typename T>
std::ptrdiff_t operator-(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock())
		throw std::runtime_error("the two ConstBlobPtrs don't point to the same object");
	return lhs.curr - rhs.curr;
}

#endif
