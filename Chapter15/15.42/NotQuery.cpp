#include "NotQuery.h"

QueryResult NotQuery::eval(const TextQuery &text) const {
	QueryResult result = query.eval(text);
	std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>();
	std::set<line_no>::iterator beg = result.begin(), end = result.end();
	std::size_t sz = result.get_file()->size();
	for (std::size_t n = 0; n != sz; ++n) {
		if (beg == end || *beg != n)
			ret_lines->insert(n);
		else if (beg != end)
			++beg;
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}
