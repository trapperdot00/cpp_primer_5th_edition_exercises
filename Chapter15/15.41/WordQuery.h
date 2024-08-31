#ifndef WORDQUERY_H
#define WORDQUERY_H

#include "Query_base.h"
#include <string>

class WordQuery : public Query_base {
	friend class Query;

	WordQuery(const std::string &s) : query_word(s) {}
	
	std::string rep() const override {
		return query_word;
	}
	QueryResult eval(const TextQuery &t) const override {
		return t.query(query_word);
	}
	WordQuery *clone() const override {
		return new WordQuery(query_word);
	}

	// Copy constructor
	WordQuery(const WordQuery &wq) : Query_base(wq), query_word(wq.query_word) {}
	// Move constructor
	WordQuery(WordQuery &&wq) noexcept : Query_base(std::move(wq)), query_word(std::move(wq.query_word)) {}
	// Copy-assignment operator
	WordQuery &operator=(const WordQuery &rhs) {
		Query_base::operator=(rhs);
		query_word = rhs.query_word;
		return *this;
	}
	// Move assignment operator
	WordQuery &operator=(WordQuery &&rhs) noexcept {
		if (this != &rhs) {
			Query_base::operator=(std::move(rhs));
			query_word = std::move(rhs.query_word);
		}
		return *this;
	}
	// Destructor
	~WordQuery() = default;

	std::string query_word;
};

#endif
