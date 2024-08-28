#ifndef WORDQUERY_H
#define WORDQUERY_H

#include "Query_base.h"
#include "Query.h"

#include <string>

class WordQuery : public Query_base {
	friend class Query;

	WordQuery(const std::string &s) : query_word(s) {
		std::cout << "WordQuery constructor" << std::endl;
	}
	
	std::string rep() const override {
		std::cout << "WordQuery::rep()" << std::endl;
		return query_word;
	}
	std::string query_word;
};

#endif
