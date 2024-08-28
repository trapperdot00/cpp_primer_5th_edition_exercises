#include "Quote.h"
#include "Bulk_quote.h"

#include <memory>
#include <vector>
#include <cstddef>
#include <numeric>
#include <iostream>

using std::cout;
using std::endl;
using std::accumulate;
using std::shared_ptr;
using std::make_shared;
using std::vector;
using std::size_t;

int main() {

	// Correct: virtual function calls will resolve at run time, depending on the dynamic type of the object
	// Dynamic binding requires a pointer to base type or a reference to base type
	// Since references aren't objects, we can't put them into containers, we have to fill the container with pointers
	vector<shared_ptr<Quote>> qpvec;

	qpvec.push_back(make_shared<Bulk_quote>("Elem1", 25, 5, 0.10));
	qpvec.push_back(make_shared<Bulk_quote>("Elem2", 29.99, 10, 0.05));
	qpvec.push_back(make_shared<Bulk_quote>("Elem3", 10, 3, 0.33));
	qpvec.push_back(make_shared<Bulk_quote>("Elem4", 5, 8, 0.5));
	qpvec.push_back(make_shared<Bulk_quote>("Elem5", 3.5, 15, 0.01));

	size_t amount = 7;
	double overall_price = accumulate(qpvec.cbegin(), qpvec.cend(), 0.0, [amount](double d, const shared_ptr<Quote> &p){ return d + p->net_price(amount); });

	cout << "Total net_price with vector<shared_ptr<Quote>>: " << overall_price << endl;
	return 0;
}
