#include "Token.h"

Token &Token::operator=(const Token &t) {
	if (tok == STR && t.tok != STR)
		sval.std::string::~string();
	else if (tok == SD && t.tok != SD)
		sdval.~Sales_data();

	if (tok == STR && t.tok == STR)
		sval = t.sval;
	else if (tok == SD && t.tok == SD)
		sdval = t.sdval;
	else
		copyUnion(t);
	tok = t.tok;
	return *this;
}

Token &Token::operator=(Token &&t) noexcept {
	if (this != &t) {
		if (tok == STR && t.tok != STR)
			sval.std::string::~string();
		else if (tok == SD && t.tok != SD)
			sdval.~Sales_data();

		if (tok == STR && t.tok == STR)
			sval = std::move(t.sval);
		else if (tok == SD && t.tok == SD)
			sdval = std::move(t.sdval);
		else
			moveUnion(std::move(t));
		tok = std::move(t.tok);
	}
	return *this;
}

Token &Token::operator=(const std::string &s) {
	if (tok == SD)
		sdval.~Sales_data();

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
	else if (tok == SD)
		sdval.~Sales_data();
	cval = c;
	tok = CHAR;
	return *this;
}

Token &Token::operator=(int i) {
	if (tok == STR)
		sval.std::string::~string();
	else if (tok == SD)
		sdval.~Sales_data();
	ival = i;
	tok = INT;
	return *this;
}

Token &Token::operator=(double d) {
	if (tok == STR)
		sval.std::string::~string();
	else if (tok == SD)
		sdval.~Sales_data();
	dval = d;
	tok = DBL;
	return *this;
}

Token &Token::operator=(const Sales_data &sd) {
	if (tok == STR)
		sval.std::string::~string();

	if (tok == SD)
		sdval = sd;
	else
		new (&sdval) Sales_data(sd);
	tok = SD;
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
		case SD:
			new (&sdval) Sales_data(t.sdval);
			break;
	}
}

void Token::moveUnion(Token &&t) noexcept {
	switch (t.tok) {
		case INT:
			ival = std::move(t.ival);
			break;
		case CHAR:
			cval = std::move(t.cval);
			break;
		case DBL:
			dval = std::move(t.dval);
			break;
		case STR:
			new (&sval) std::string(std::move(t.sval));
			break;
		case SD:
			new (&sdval) Sales_data(std::move(t.sdval));
			break;
	}
}
