#ifndef NOTQUERY_H
#define NOTQUERY_H

#include "Query.h"
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
	NotQuery *clone() const override {
		return new NotQuery(query);
	}

	// Copy constructor
	NotQuery(const NotQuery &nq) : Query_base(nq), query(nq.query) {}
	// Move constructor
	NotQuery(NotQuery &&nq) noexcept : Query_base(std::move(nq)), query(std::move(nq.query)) {}
	// Copy-assignment operator
	NotQuery &operator=(const NotQuery &rhs) {
		Query_base::operator=(rhs);
		query = rhs.query;
		return *this;
	}
	// Move-assignment operator
	NotQuery &operator=(NotQuery &&rhs) noexcept {
		if (this != &rhs) {
			Query_base::operator=(std::move(rhs));
			query = std::move(rhs.query);
		}
		return *this;
	}
	// Destructor
	~NotQuery() = default;

	Query query;
};

inline Query operator~(const Query &operand) {
	return new NotQuery(operand);
}

#endif
