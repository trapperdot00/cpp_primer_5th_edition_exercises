#ifndef NOTQUERY_H
#define NOTQUERY_H

#include "Query.h"
#include "DebugDelete.h"
#include <cstddef>

class NotQuery : public Query_base {
	friend Query operator~(const Query &);
	NotQuery(const Query &q) : query(q) {
		std::cout << "NotQuery::NotQuery" << std::endl;
	}

	std::string rep() const override {
		std::cout << "NotQuery::rep" << std::endl;
		return "~(" + query.rep() + ")";
	}
	QueryResult eval(const TextQuery &) const override;

	Query query;
};

inline Query operator~(const Query &operand) {
	return std::shared_ptr<Query_base>(new NotQuery(operand), DebugDelete());
}

#endif
