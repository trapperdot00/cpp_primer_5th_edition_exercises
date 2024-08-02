
#include "TextQuery.h"

TextQuery::TextQuery(std::ifstream &in) : text(std::make_shared<StrVec>()) {
	std::size_t currLine = 0;
	for (std::string line; std::getline(in, line); text->push_back(line)) {
		std::istringstream stream(line);
		std::string word;
		while (stream >> word) {
			std::shared_ptr<std::set<std::size_t>> &lines = wordLines[word];
			if (!lines)
				lines.reset(new std::set<std::size_t>);
			lines->insert(currLine);
		}
		++currLine;
	}
}

QueryResult TextQuery::query(const std::string &s) const {
	static std::shared_ptr<std::set<std::size_t>> nodata = std::make_shared<std::set<std::size_t>>();
	if (wordLines.find(s) == wordLines.end())
		return QueryResult(s, text, nodata);
	return QueryResult(s, text, (*wordLines.find(s)).second);
}
