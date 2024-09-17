#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <map>
#include <set>
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <tuple>

class TextQuery {
public:
	typedef std::vector<std::string>::size_type line_no;
	typedef std::tuple<std::string,
			std::shared_ptr<std::set<line_no>>,
			std::shared_ptr<std::vector<std::string>>>
			Result;
	TextQuery(std::ifstream &in) : file(std::make_shared<std::vector<std::string>>()) {
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
	
   	Result query(const std::string &) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

#endif
