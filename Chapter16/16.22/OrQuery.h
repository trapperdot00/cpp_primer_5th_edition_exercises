#ifndef ORQUERY_H
#define ORQUERY_H

#include "BinaryQuery.h"
#include "DebugDelete.h"

class OrQuery : public BinaryQuery {
	friend Query operator|(const Query &, const Query &);
	OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {}
	QueryResult eval(const TextQuery &) const override;
};

inline Query operator|(const Query &lhs, const Query &rhs) {
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs), DebugDelete());
}

#endif
