#ifndef ORQUERY_H
#define ORQUERY_H

#include "BinaryQuery.h"

class OrQuery : public BinaryQuery {
	friend Query operator|(const Query &, const Query &);
	OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {}
};

#endif
