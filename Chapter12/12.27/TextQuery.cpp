#include "TextQuery.h"

TextQuery::TextQuery(std::ifstream &input) {
	std::size_t lineNo = 1;
	for (std::string line; std::getline(input, line); text.push_back(line)) {
		std::istringstream stream(line);
		std::string word;
		while (stream >> word) {
			std::set<std::size_t> &lineSet = word_lines[word];
			lineSet.insert(lineNo);
		}
		++lineNo;
	}
}

QueryResult::QueryResult(std::string s, std::set<std::size_t> n, std::vector<std::string> t) : toFind(s), lineNo(n), textLines(t) {}

QueryResult TextQuery::query(const std::string &s) const {
	if (word_lines.find(s) == word_lines.end()) {
		return QueryResult(s, std::set<std::size_t>(), text);
	}
	return QueryResult(s, word_lines.find(s)->second, text);
}

std::ostream &print(std::ostream &os, const QueryResult &q) {
	std::size_t occurs = q.lineNo.size();
	os << q.toFind << " occurs " << occurs << " times\n";
	std::size_t currOcc = 0, currLine = 1;
	while (currOcc != occurs) {
		std::string line = q.textLines[currLine-1];
		if (line.find(q.toFind) != std::string::npos) {
			os << "   (line " << currLine << ") " << line << std::endl;
			++currOcc;
		}
		++currLine;
	}
	return os;
}
