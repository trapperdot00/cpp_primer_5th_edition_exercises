#include "TextQuery.h"

QueryResult TextQuery::query(const std::string &s) const  {
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	std::map<std::string, std::shared_ptr<std::set<line_no>>>::const_iterator findIt = wm.find(s);
	if (findIt == wm.cend())
		return QueryResult(s, nodata, file);
	else
		return QueryResult(s, findIt->second, file);
}
