#ifndef QUERY_BASE_H
#define QUERY_BASE_H

#include "QueryResult.h"

#include <string>
#include <utility>

class Query_base {
	friend class Query;
protected:
	using line_no = TextQuery::line_no;

	Query_base() = default;
	Query_base(const Query_base &) = default;
	Query_base(Query_base &&) = default;
	Query_base &operator=(const Query_base &) = default;
	Query_base &operator=(Query_base &&) = default;
	virtual ~Query_base() = default;
private:
	virtual std::string rep() const = 0;
	virtual QueryResult eval(const TextQuery &) const = 0;

	virtual Query_base *clone() const = 0;
};

#endif
