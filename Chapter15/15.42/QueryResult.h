#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include "StrBlob.h"

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <memory>
#include <stdexcept>
#include <cstddef>

#include "TextQuery.h"

class QueryResult {
friend std::ostream &print(std::ostream &, const QueryResult &, std::size_t, std::size_t);
public:
	typedef StrBlob::size_type line_no;
	QueryResult(const std::string &s, std::shared_ptr<std::set<line_no>> l, std::shared_ptr<StrBlob> f) : sought(s), line_nums(l), file(f) {}
	
	std::set<line_no>::iterator begin() { return line_nums->begin(); }
	std::set<line_no>::iterator end() { return line_nums->end(); }
	std::shared_ptr<StrBlob> get_file() const { return file; }
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> line_nums;
	std::shared_ptr<StrBlob> file;
};

#endif
