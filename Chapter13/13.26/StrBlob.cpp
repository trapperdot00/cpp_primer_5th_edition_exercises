#include "StrBlob.h"

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { }

StrBlob::StrBlob(const StrBlob &obj) : data(std::make_shared<std::vector<std::string>>(*obj.data)) { }
StrBlob &StrBlob::operator=(const StrBlob &rhs) {
	data = std::make_shared<std::vector<std::string>>(*rhs.data);
	return *this;
}

void StrBlob::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}

std::string &StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}

const std::string &StrBlob::front() const {
	check(0, "front on empty const StrBlob");
	return data->front();
}

std::string &StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string &StrBlob::back() const {
	check(0, "back on empty const StrBlob");
	return data->back();
}

void StrBlob::pop_back() {
	check(9, "pop_back on empty StrBlob");
	data->pop_back();
}

StrBlobPtr StrBlob::begin() {
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
	return StrBlobPtr(*this, data->size());
}

ConstStrBlobPtr StrBlob::cbegin() const {
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const {
	return ConstStrBlobPtr(*this, data->size());
}

// StrBlobPtr

StrBlobPtr::StrBlobPtr() : curr(0) { }
StrBlobPtr::StrBlobPtr(StrBlob &a, std::size_t i) : wptr(a.data), curr(i) { }

std::string &StrBlobPtr::deref() const {
	std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const {
	std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
	if (!ret) {
		throw std::runtime_error("unbound StrBlobPtr");
	}
	if (i >= ret->size()) {
		throw std::out_of_range(msg);
	}
	return ret;
}

// ConstStrBlobPtr

ConstStrBlobPtr::ConstStrBlobPtr() : curr(0) { }
ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &a, std::size_t i) : wptr(a.data), curr(i) { }

const std::string &ConstStrBlobPtr::deref() const {
	std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
	return (*p)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
	std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
	if (!ret) {
		throw std::runtime_error("unbound ConstStrBlobPtr");
	}
	if (i >= ret->size()) {
		throw std::out_of_range(msg);
	}
	return ret;
}
