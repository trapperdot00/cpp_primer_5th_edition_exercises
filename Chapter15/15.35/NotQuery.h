#ifndef NOTQUERY_H
#define NOTQUERY_H

#include "Query_base.h"

class NotQuery : public Query_base {
	friend Query operator~(const Query &);
	NotQuery(const Query &q) : query(q) {}

	std::string rep() const { return "~(" + query.rep() + ")"; }
	Query query;
};

#endif
