#ifndef QUERY_H
#define QUERY_H

#include "TextQuery.h"
#include "QueryResult.h"

#include <string>
#include <memory>
#include <iostream>

#include "Query_base.h"
#include "WordQuery.h"

class Query {
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
public:
	Query(const std::string &s) : q(new WordQuery(s)) {}

	std::string rep() const {
		return q->rep();
	}
	QueryResult eval(const TextQuery &t) const {
		return q->eval(t);
	}
	// Copy constructor
	Query(const Query &query) : q(query.clone()) {}
	// Move constructor
	Query(Query &&query) : q(query.q) {
		query.q = nullptr;
	}
	// Copy-assignment operator
	Query &operator=(const Query &rhs) {
		Query_base *temp = rhs.clone();
		delete q;
		q = temp;
		return *this;
	}
	// Move-assignment operator
	Query &operator=(Query &&rhs) {
		if (this != &rhs) {
			delete q;
			q = rhs.q;
			rhs.q = nullptr;
		}
		return *this;
	}
	// Destructor
	~Query() {
		delete q;
	}
private:
	Query(Query_base *query) : q(query) {}
	Query_base *clone() const {
		return q->clone();
	}

	Query_base *q = nullptr;
};

std::ostream &operator<<(std::ostream &, const Query &);

#endif
