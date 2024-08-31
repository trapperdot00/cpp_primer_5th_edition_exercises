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

#include <cctype>
#include <algorithm>

class QueryResult;

class TextQuery {
public:
	typedef StrBlob::size_type line_no;
	TextQuery(std::ifstream &in) : file(std::make_shared<StrBlob>()) {
		line_no line_num = 0;
		for (std::string line; std::getline(in, line); file->push_back(line), ++line_num) {
			std::string word;
			std::istringstream stream(line);
			while (stream >> word) {
				
				// erase not alphanumeric characters from the current word
				word.erase(std::remove_if(word.begin(), word.end(), [](char c){ return !std::isalnum(c); }), word.end());
				
				// transform current word's all characters to lowercase
				std::transform(word.begin(), word.end(), word.begin(), [](char c){ return std::tolower(c); });
				
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

#include "QueryResult.h"

#endif
