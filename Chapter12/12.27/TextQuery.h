#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <memory>
#include <cstddef>
#include <iostream>
#include <algorithm>

class QueryResult;
class TextQuery {
public:
	TextQuery(std::ifstream &);
	QueryResult query(const std::string &) const;
private:
	std::vector<std::string> text;
	std::map<std::string, std::set<std::size_t>> word_lines;
};

class QueryResult {
	friend std::ostream &print(std::ostream &, const QueryResult &);
public:
	QueryResult(std::string, std::set<std::size_t>, std::vector<std::string>);
private:
	std::string toFind;
	std::set<std::size_t> lineNo;
	std::vector<std::string> textLines;
};

std::ostream &print(std::ostream &, const QueryResult &); 

#endif
