#include "StrBlob.h"

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}

std::string &StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string &StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

ConstStrBlobPtr StrBlob::cbegin() const { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::cend() const { return ConstStrBlobPtr(*this, data->size()); }

bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
	return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
	return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
	return *lhs.data < *rhs.data;
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
	return rhs < lhs;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
	return !(lhs > rhs);
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
	return !(lhs < rhs);
}
