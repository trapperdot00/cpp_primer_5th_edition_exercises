#include <iostream>

#include "Sales_data.h"

int main() {
	const std::string Sales_data::*RBookNoP = Sales_data::bookNo_pointer();
	Sales_data s1("book1", 10, 25), s2("book2", 2, 5);
	Sales_data *sp1 = &s1, *sp2 = &s2;
	
	std::cout << s1.*RBookNoP << '\t' << sp1->*RBookNoP << '\n'
			  << s2.*RBookNoP << '\t' << sp2->*RBookNoP << std::endl;

	return 0;
}
