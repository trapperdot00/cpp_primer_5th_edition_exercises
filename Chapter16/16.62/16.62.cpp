#include "Sales_data.h"
#include <unordered_set>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::unordered_multiset;

int main() {
	unordered_multiset<Sales_data> SDset;
	for (Sales_data temp; cin >> temp; SDset.insert(temp)) ;
	for (unordered_multiset<Sales_data>::const_iterator it = SDset.cbegin();
		 it != SDset.cend(); ++it)
		cout << *it << endl;
	return 0;
}
