#include "Token.h"

Token &Token::operator=(const Token &t) {
	if (tok == STR && t.tok != STR)
		sval.std::string::~string();

	if (tok == STR && t.tok == STR)
		sval = t.sval;
	else
		copyUnion(t);
	tok = t.tok;
	return *this;
}

Token &Token::operator=(const std::string &s) {
	if (tok == STR)
		sval = s;
	else
		new (&sval) std::string(s);
	tok = STR;
	return *this;
}

Token &Token::operator=(char c) {
	if (tok == STR)
		sval.std::string::~string();
	cval = c;
	tok = CHAR;
	return *this;
}

Token &Token::operator=(int i) {
	if (tok == STR)
		sval.std::string::~string();
	ival = i;
	tok = INT;
	return *this;
}

Token &Token::operator=(double d) {
	if (tok == STR)
		sval.std::string::~string();
	dval = d;
	tok = DBL;
	return *this;
}

void Token::copyUnion(const Token &t) {
	switch (t.tok) {
		case INT:
			ival = t.ival;
			break;
		case CHAR:
			cval = t.cval;
			break;
		case DBL:
			dval = t.dval;
			break;
		case STR:
			new (&sval) std::string(t.sval);
			break;
	}
}
