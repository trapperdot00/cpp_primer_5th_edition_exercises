#ifndef BLOB_H
#define BLOB_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <utility>
#include <stdexcept>

#include "SharedPtr.h"

template <typename T> class Blob;

template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);

template <typename T>
class Blob {
	friend bool operator==<T>(const Blob<T> &, const Blob<T> &);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	Blob();
	Blob(std::initializer_list<T>);
	template <typename It>
	Blob(It, It);

	typename std::vector<T>::iterator begin() { return data->begin(); }
	typename std::vector<T>::iterator end() { return data->end(); }
	typename std::vector<T>::const_iterator cbegin() const { return data->cbegin(); }
	typename std::vector<T>::const_iterator cend() const { return data->cend(); }

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
	SharedPtr<std::vector<T>> data;
};

template <typename T>
Blob<T>::Blob() : data(MakeShared<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(MakeShared<std::vector<T>>(il)) {}

template <typename T>
template <typename It>
	Blob<T>::Blob(It b, It e) : data(MakeShared<std::vector<T>>(b, e)) {}

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

#endif
