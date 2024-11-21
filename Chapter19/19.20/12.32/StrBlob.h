#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
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

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	
	void push_back(const std::string &s) { data->push_back(s); }
	void pop_back();
	
	std::string &front();
	std::string &back();

	StrBlobPtr begin();
	StrBlobPtr end();

	ConstStrBlobPtr cbegin() const;
	ConstStrBlobPtr cend() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type, const std::string &) const;
};

#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"

#endif
