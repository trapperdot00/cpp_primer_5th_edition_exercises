#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include "StrVec.h"
#include <set>
#include <memory>
#include <map>
#include <fstream>
#include <cstddef>
#include <string>
#include <sstream>

class QueryResult;

class TextQuery {
public:
	TextQuery(std::ifstream &);
	
	QueryResult query(const std::string &) const;

private:
	std::shared_ptr<StrVec> text;
	std::map<std::string, std::shared_ptr<std::set<std::size_t>>> wordLines;
};

#include "QueryResult.h"

#endif
