#ifndef WORDQUERY_H
#define WORDQUERY_H

#include "Query_base.h"
#include <string>

class WordQuery : public Query_base {
	friend class Query;

	WordQuery(const std::string &s) : query_word(s) {}
	
	std::string rep() const override { return query_word; }
	std::string query_word;
};

#endif
