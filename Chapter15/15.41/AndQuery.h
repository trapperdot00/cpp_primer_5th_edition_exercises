#ifndef ANDQUERY_H
#define ANDQUERY_H

#include "BinaryQuery.h"
#include <algorithm>
#include <iterator>

class AndQuery : public BinaryQuery {
	friend Query operator&(const Query &, const Query &);
	AndQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "&") {}
	QueryResult eval(const TextQuery &) const override;

	AndQuery *clone() const override {
		return new AndQuery(lhs, rhs);
	}

	// Copy constructor
	AndQuery(const AndQuery &aq) : BinaryQuery(aq) {}
	// Move constructor
	AndQuery(AndQuery &&aq) noexcept : BinaryQuery(std::move(aq)) {}
	// Copy-assignment operator
	AndQuery &operator=(const AndQuery &rhs) {
		BinaryQuery::operator=(rhs);
		return *this;
	}
	// Move-assignment operator
	AndQuery &operator=(AndQuery &&rhs) noexcept {
		if (this != &rhs) {
			BinaryQuery::operator=(std::move(rhs));
		}
		return *this;
	}
	// Destructor
	~AndQuery() = default;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
	return new AndQuery(lhs, rhs);
}

#endif
