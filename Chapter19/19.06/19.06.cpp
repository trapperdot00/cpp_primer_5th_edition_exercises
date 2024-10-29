#include "AllQuery.h"
#include <iostream>

void cast_test(Query_base *pb) {
	if (AndQuery *p = dynamic_cast<AndQuery *>(pb)) {
		std::cout << "cast works" << std::endl;
	} else {
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

	cast_test(aq.get());
	cast_test(oq.get());

	return 0;
}
