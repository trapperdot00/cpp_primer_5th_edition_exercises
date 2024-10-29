#include "AllQuery.h"
#include <iostream>
#include <typeinfo>

void cast_test(const Query_base &pb) {
	try {
		const AndQuery &aq = dynamic_cast<const AndQuery &>(pb);
		std::cout << "cast works" << std::endl;
	} catch (const std::bad_cast &e) {
		std::cout << "cast failed" << std::endl;
	}
}

int main() {
	// q1 and q2 point WordQuery objects
	Query q1("the");
	Query q2("an");

	// aq points to an AndQuery object
	Query aq = q1 & q2;

	// oq points to an OrQuery object
	Query oq = q1 | q2;	

	cast_test(aq.value());
	cast_test(oq.value());

	return 0;
}
