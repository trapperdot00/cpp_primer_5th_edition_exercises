#ifndef QUERY_H
#define QUERY_H

#include "TextQuery.h"
#include "QueryResult.h"
#include "Query_base.h"

#include <string>
#include <memory>
#include <iostream>

class Query {
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
public:
	Query(const std::string &s);

	std::string rep() const {
		std::cout << "Query::rep()" << std::endl;
		return q->rep();
	}
private:
	Query(std::shared_ptr<Query_base> query) : q(query) {
		std::cout << "Query constructor (shared_ptr)" << std::endl;
	}

	std::shared_ptr<Query_base> q;
};

#include "WordQuery.h"
#include "NotQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"

inline Query::Query(const std::string &s) : q(new WordQuery(s)) {
	std::cout << "Query constructor (string)" << std::endl;
}

inline Query operator~(const Query &operand) {
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

inline Query operator&(const Query &lhs, const Query &rhs) {
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

inline Query operator|(const Query &lhs, const Query &rhs) {
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}


std::ostream &operator<<(std::ostream &, const Query &);

#endif
