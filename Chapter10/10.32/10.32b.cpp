#include "Sales_item.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

using std::istream_iterator;
using std::ostream_iterator;
using std::cin;
using std::vector;
using std::sort;
using std::accumulate;
using std::for_each;
using std::cout;
using std::endl;
using std::find_if;

bool compareIsbns(const Sales_item &item1, const Sales_item &item2) {
	return item1.isbn() < item2.isbn();
}

int main() {
	istream_iterator<Sales_item> inIter(cin), eof;
	ostream_iterator<Sales_item> outIter(cout, "\n");
	vector<Sales_item> trans(inIter, eof);
	sort(trans.begin(), trans.end(), compareIsbns);
	//for_each(trans.cbegin(), trans.cend(), [](const Sales_item &item) { cout << item << endl; });
	vector<Sales_item>::const_iterator beg = trans.cbegin(), end = beg;
	while (beg != trans.cend()) {
		end = find_if(beg, trans.cend(), [&beg](const Sales_item &item){ return beg->isbn() != item.isbn(); });
		Sales_item total(beg->isbn());
		total = accumulate(beg, end, total);
		outIter = total;
		beg = end;
	}
	return 0;
}
