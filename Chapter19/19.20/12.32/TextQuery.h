#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include "StrBlob.h"

#include <map>
#include <set>
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class TextQuery {
public:
	class QueryResult;

	typedef StrBlob::size_type line_no;
	TextQuery(std::ifstream &in) : file(std::make_shared<StrBlob>()) {
		line_no line_num = 0;
		for (std::string line; std::getline(in, line); file->push_back(line), ++line_num) {
			std::string word;
			std::istringstream stream(line);
			while (stream >> word) {
				std::shared_ptr<std::set<line_no>> &lines = wm[word];
				if (!lines)
					lines.reset(new std::set<line_no>);
				lines->insert(line_num);
			}
		}
	}
	QueryResult query(const std::string &) const;
private:
	std::shared_ptr<StrBlob> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class TextQuery::QueryResult {
	friend std::ostream &print(std::ostream &, const TextQuery::QueryResult &);
public:
	QueryResult(const std::string &s, std::shared_ptr<std::set<line_no>> l, std::shared_ptr<StrBlob> f)
		: sought(s), line_nums(l), file(f) {}
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> line_nums;
	std::shared_ptr<StrBlob> file;
};

#endif
