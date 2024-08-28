#include "Quote.h"
#include "Bulk_quote.h"

#include <iostream>
#include <vector>
#include <numeric>
#include <cstddef>

using std::cout;
using std::endl;
using std::vector;
using std::accumulate;
using std::size_t;

int main() {
	vector<Quote> qvec;

	qvec.push_back(Bulk_quote("Elem1", 25, 5, 0.10));
	qvec.push_back(Bulk_quote("Elem2", 29.99, 10, 0.05));
	qvec.push_back(Bulk_quote("Elem3", 10, 3, 0.33));
	qvec.push_back(Bulk_quote("Elem4", 5, 8, 0.5));
	qvec.push_back(Bulk_quote("Elem5", 3.5, 15, 0.01));
	
	size_t amount = 7;
	double overall_price = accumulate(qvec.cbegin(), qvec.cend(), 0.0, [amount](double d, const Quote &q) { return d + q.net_price(amount); } );
	cout << "Total net_price with vector<Quote>: " << overall_price << endl;
	return 0;
}
