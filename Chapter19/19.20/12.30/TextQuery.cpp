#include "TextQuery.h"

std::ostream &print(std::ostream &os, const TextQuery::QueryResult &q) {
	os << q.sought << " occurs " << q.line_nums->size() << " times\n";
	for (TextQuery::line_no num : *q.line_nums)
		os << "\t(line " << num + 1 << ") " << *(q.file->begin() + num) << std::endl;
	return os;
}

TextQuery::QueryResult TextQuery::query(const std::string &s) const  {
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	std::map<std::string, std::shared_ptr<std::set<line_no>>>::const_iterator findIt = wm.find(s);
	if (findIt == wm.cend())
		return QueryResult(s, nodata, file);
	else
		return QueryResult(s, findIt->second, file);
}
