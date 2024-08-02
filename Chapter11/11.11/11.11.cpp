#include <set>
#include "Sales_item.h"

using std::multiset;

bool compareIsbns(const Sales_item &lhs, const Sales_item &rhs) {
	return lhs.isbn() < rhs.isbn();
}

int main() {
	//multiset<Sales_item, decltype(compareIsbns)*> bookstore(compareIsbns);
	multiset<Sales_item, bool(*)(const Sales_item&, const Sales_item&)> bookstore(compareIsbns);
	return 0;
}
