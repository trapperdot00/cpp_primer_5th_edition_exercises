#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <new>

#include "Sales_data.h"

class Token {
public:
	Token() : tok(INT), ival(0) {}
	Token(const Token &t) : tok(t.tok) { copyUnion(t); }
	Token &operator=(const Token &);
	~Token() {
		switch (tok) {
			case STR:
				sval.std::string::~string();
				break;
			case SD:
				sdval.~Sales_data();
				break;
			default:
				break;
		}
	}

	Token &operator=(const std::string &);
	Token &operator=(char);
	Token &operator=(int);
	Token &operator=(double);
	Token &operator=(const Sales_data &);
private:
	enum {CHAR, INT, DBL, STR, SD} tok;
	union {
		char cval;
		int ival;
		double dval;
		std::string sval;
		Sales_data sdval;
	};
	void copyUnion(const Token &);
};

#endif
