#ifndef NOTQUERY_H
#define NOTQUERY_H

#include "Query_base.h"

class NotQuery : public Query_base {
	friend Query operator~(const Query &);
	NotQuery(const Query &q) : query(q) {
		std::cout << "NotQuery constructor" << std::endl;
	}

	std::string rep() const {
		std::cout << "NotQuery::rep()" << std::endl;
		return "~(" + query.rep() + ")"; 
	}
	Query query;
};

#endif
