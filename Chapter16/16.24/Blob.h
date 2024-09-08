#ifndef BLOB_H
#define BLOB_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <utility>
#include <stdexcept>

template <typename T> class Blob;
template <typename T> class BlobPtr;
template <typename T> class ConstBlobPtr;

template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);

template <typename T>
class Blob {
	friend class BlobPtr<T>;
	friend class ConstBlobPtr<T>;
	friend bool operator==<T>(const Blob<T> &, const Blob<T> &);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	Blob();
	Blob(std::initializer_list<T>);
	template <typename It>
	Blob(It, It);

	BlobPtr<T> begin();
	BlobPtr<T> end();
	ConstBlobPtr<T> cbegin() const;
	ConstBlobPtr<T> cend() const;

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const T &elem) {	data->push_back(elem); }
	void push_back(T &&elem) { data->push_back(std::move(elem)); }
	void pop_back();
	
	T &front();
	const T &front() const;
	T &back();
	const T &back() const;
	T &operator[](size_type);
	const T &operator[](size_type) const;

private:
	void check(size_type, const std::string &) const;
	std::shared_ptr<std::vector<T>> data;
};

template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}

template <typename T>
template <typename It>
	Blob<T>::Blob(It b, It e) : data(std::make_shared<std::vector<T>>(b, e)) {}

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template <typename T>
T &Blob<T>::front() {
	check(0, "front on empty Blob");
	return data->front();
}
template <typename T>
const T &Blob<T>::front() const {
	check(0, "front on empty Blob");
	return data->front();
}
template <typename T>
T &Blob<T>::back() {
	check(0, "back on empty Blob");
	return data->back();
}
template <typename T>
const T &Blob<T>::back() const {
	check(0, "back on empty Blob");
	return data->back();
}
template <typename T>
T &Blob<T>::operator[](size_type i) {
	check(i, "subscript out of range");
	return (*data)[i];
}
template <typename T>
const T &Blob<T>::operator[](size_type i) const {
	check(i, "subscript out of range");
	return (*data)[i];
}
template <typename T>
void Blob<T>::pop_back() {
	check(0, "pop back on empty Blob");
	data->pop_back();
}

// Equality operators for Blob
template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
	return *lhs.data == *rhs.data;
}
template <typename T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs) {
	return !(lhs == rhs);
}

#include "BlobPtr.h"
#include "ConstBlobPtr.h"

// Blob member functions dependent on the BlobPtr types

template <typename T>
BlobPtr<T> Blob<T>::begin() {
	return BlobPtr<T>(*this, 0);
}
template <typename T>
BlobPtr<T> Blob<T>::end() {
	return BlobPtr<T>(*this, size());
}
template <typename T>
ConstBlobPtr<T> Blob<T>::cbegin() const {
	return ConstBlobPtr<T>(*this, 0);
}
template <typename T>
ConstBlobPtr<T> Blob<T>::cend() const {
	return ConstBlobPtr<T>(*this, size());
}

#endif
