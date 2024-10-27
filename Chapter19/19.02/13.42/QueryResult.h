#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include "TextQuery.h"

#include <string>
#include <memory>
#include <set>
#include <cstddef>
#include <iostream>

class QueryResult {
	friend std::ostream &print(std::ostream &, const QueryResult &);
public:
	QueryResult(const std::string &, const std::shared_ptr<StrVec> &, const std::shared_ptr<std::set<std::size_t>> &);
private:
	std::string sought;
	std::shared_ptr<StrVec> text;
	std::shared_ptr<std::set<std::size_t>> lineNums;
};

#endif
