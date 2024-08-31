#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include "Query.h"

class BinaryQuery : public Query_base {
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s)
		: lhs(l), rhs(r), opSym(s) {}
	std::string rep() const {
			return "(" + lhs.rep() + " "
		   			   + opSym + " "
					   + rhs.rep() + ")";
	}

	// Copy constructor
	BinaryQuery(const BinaryQuery &bq)
			: Query_base(bq), lhs(bq.lhs), rhs(bq.rhs), opSym(bq.opSym) {}
	// Move constructor
	BinaryQuery(BinaryQuery &&bq) noexcept
			: Query_base(std::move(bq)), lhs(std::move(bq.lhs)),
			rhs(std::move(bq.rhs)), opSym(std::move(bq.opSym)) {}
	// Copy-assignment operator
	BinaryQuery &operator=(const BinaryQuery &rhs_bq) {
		Query_base::operator=(rhs_bq);
		lhs = rhs_bq.lhs;
		rhs = rhs_bq.rhs;
		opSym = rhs_bq.opSym;
		return *this;
	}
	// Move-assignment operator
	BinaryQuery &operator=(BinaryQuery &&rhs_bq) noexcept {
		if (this != &rhs_bq) {
			Query_base::operator=(std::move(rhs_bq));
			lhs = std::move(rhs_bq.lhs);
			rhs = std::move(rhs_bq.rhs);
			opSym = std::move(rhs_bq.opSym);
		}
		return *this;
	}
	// Destructor
	~BinaryQuery() = default;

	Query lhs, rhs;
	std::string opSym;
};

#endif
