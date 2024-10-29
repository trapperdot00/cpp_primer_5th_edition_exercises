#include "AllQuery.h"
#include <iostream>
#include <typeinfo>

bool sameType(const Query_base *p1, const Query_base *p2) {
	return typeid(*p1) == typeid(*p2);
}

bool isAndQuery(const Query_base *p) {
	return typeid(*p) == typeid(AndQuery);
}

int main() {
	// q1 and q2 point WordQuery objects
	Query q1("the");
	Query q2("an");

	// aq points to an AndQuery object
	Query aq = q1 & q2;

	// oq points to an OrQuery object
	Query oq = q1 | q2;	

	if (sameType(aq.get(), oq.get()))
		std::cout << "The two pointers point to the same types" << std::endl;
	else
		std::cout << "The two pointers point to two different types" << std::endl;

	if (isAndQuery(aq.get()))
		std::cout << "aq points to an AndQuery" << std::endl;
	
	if (isAndQuery(oq.get()))
		std::cout << "oq points to an AndQuery" << std::endl;
	return 0;
}
