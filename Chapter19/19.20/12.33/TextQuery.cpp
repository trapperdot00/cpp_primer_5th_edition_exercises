#include "TextQuery.h"

std::ostream &print(std::ostream &os, const TextQuery::QueryResult &q) {
	os << q.sought << " occurs " << q.line_nums->size() << " times\n";
	for (auto it = q.line_nums->cbegin(); it != q.line_nums->cend(); ++it) {
		auto num = *it;
		StrBlobPtr iter(*(q.file));
		for (TextQuery::line_no index = 0; index != num; ++index)
			iter.incr();
		os << "\t(line " << num + 1 << ") " << iter.deref() << std::endl;
	}
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
