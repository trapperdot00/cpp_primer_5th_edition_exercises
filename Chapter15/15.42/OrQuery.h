#ifndef ORQUERY_H
#define ORQUERY_H

#include "BinaryQuery.h"

class OrQuery : public BinaryQuery {
	friend Query operator|(const Query &, const Query &);
	OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {}
	QueryResult eval(const TextQuery &) const override;

	OrQuery *clone() const override {
		return new OrQuery(lhs, rhs);
	}

	// Copy constructor
	OrQuery(const OrQuery &oq) : BinaryQuery(oq) {}
	// Move constructor
	OrQuery(OrQuery &&oq) noexcept : BinaryQuery(std::move(oq)) {}
	// Copy-assignment operator
	OrQuery &operator=(const OrQuery &rhs) {
		BinaryQuery::operator=(rhs);
		return *this;
	}
	// Move-assignment operator
	OrQuery &operator=(OrQuery &&rhs) noexcept {
		if (this != &rhs) {
			BinaryQuery::operator=(std::move(rhs));
		}
		return *this;
	}
	// Destructor
	~OrQuery() = default;
};

inline Query operator|(const Query &lhs, const Query &rhs) {
	return new OrQuery(lhs, rhs);
}

#endif
