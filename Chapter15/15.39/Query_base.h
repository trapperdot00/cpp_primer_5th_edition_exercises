#ifndef QUERY_BASE_H
#define QUERY_BASE_H

#include "QueryResult.h"

#include <string>

class Query_base {
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual std::string rep() const = 0;
	virtual QueryResult eval(const TextQuery &) const = 0;
};

#endif
