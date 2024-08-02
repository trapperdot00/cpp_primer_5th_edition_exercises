#include "Sales_item.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <iterator>

using std::sort;
using std::back_inserter;
using std::accumulate;
using std::cout;
using std::cin;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::vector;
using std::find;
using std::find_if;
using std::copy;
using std::accumulate;

int main() {
	vector<Sales_item> transactions;
	istream_iterator<Sales_item> inIter(cin), eof;
	copy(inIter, eof, back_inserter(transactions));

	sort(transactions.begin(), transactions.end(), compareIsbn);

	for (vector<Sales_item>::const_iterator beg = transactions.cbegin(), end = beg; beg != transactions.cend(); beg = end) {
		end = find_if(beg, transactions.cend(), [&beg](const Sales_item &item) { return beg->isbn() != item.isbn(); } );
		Sales_item total = beg->isbn();
		total = accumulate(beg, end, total);
		cout << total << endl;
	}
	
	return 0;
}
