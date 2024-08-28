#ifndef ANDQUERY_H
#define ANDQUERY_H

#include "BinaryQuery.h"

class AndQuery : public BinaryQuery {
	friend Query operator&(const Query &, const Query &);
	AndQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "&") {
		std::cout << "AndQuery constructor" << std::endl;
	}
};

#endif
