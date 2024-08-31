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
private:
	Query(std::shared_ptr<Query_base> query) : q(query) {}

	std::shared_ptr<Query_base> q;
};

std::ostream &operator<<(std::ostream &, const Query &);

#endif
