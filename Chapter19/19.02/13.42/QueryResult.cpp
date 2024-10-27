#include "QueryResult.h"

QueryResult::QueryResult(const std::string &s, const std::shared_ptr<StrVec> &t, const std::shared_ptr<std::set<std::size_t>> &p) : sought(s), text(t), lineNums(p) {}

std::ostream &print(std::ostream &os, const QueryResult &q) {
	os << "Selected word: " << q.sought << '\n';
	if (q.lineNums->empty())
		os << "\tNot found" << '\n';
	for (std::set<std::size_t>::const_iterator it = q.lineNums->cbegin(); it != q.lineNums->cend(); ++it) {
		os << "\t(line " << (*it) + 1 << ") " << *(q.text->begin() + *it) << '\n';
	}
	return os;
}
