#include "TextQuery.h"


typename TextQuery::Result TextQuery::query(const std::string &s) const  {
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	std::map<std::string, std::shared_ptr<std::set<line_no>>>::const_iterator findIt = wm.find(s);
	if (findIt == wm.cend())
		return Result(s, nodata, file);
	else
		return Result(s, findIt->second, file);
}
