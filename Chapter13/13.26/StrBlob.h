#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <memory>
#include <string>
#include <initializer_list>
#include <stdexcept>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;
	
	StrBlob();
	StrBlob(std::initializer_list<std::string>);

	StrBlob(const StrBlob &);
	StrBlob &operator=(const StrBlob &);
	
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();

	std::string &front();
	const std::string &front() const;
	std::string &back();
	const std::string &back() const;

	StrBlobPtr begin();
	StrBlobPtr end();

	ConstStrBlobPtr cbegin() const;
	ConstStrBlobPtr cend() const;

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type, const std::string &) const;
};

class StrBlobPtr {
public:
	StrBlobPtr();
	StrBlobPtr(StrBlob &, std::size_t = 0);

	std::string &deref() const;
	StrBlobPtr &incr();

private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;

	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

class ConstStrBlobPtr {
public:
	ConstStrBlobPtr();
	ConstStrBlobPtr(const StrBlob &, std::size_t = 0);

	const std::string &deref() const;
	ConstStrBlobPtr &incr();

private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;

	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

#endif
