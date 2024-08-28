#include "Quote.h"
#include "Bulk_quote.h"
#include "Basket.h"

#include <iostream>
#include <cstddef>

using std::size_t;
using std::cout;
using std::endl;

int main() {
	Basket bsk;

	size_t amount = 7;
	// weird logic, but produces the same output as 15.29
	for (size_t i = 0; i != amount; ++i) {
		bsk.add_item(Bulk_quote("Elem1", 25, 5, 0.10));
		bsk.add_item(Bulk_quote("Elem2", 29.99, 10, 0.05));
		bsk.add_item(Bulk_quote("Elem3", 10, 3, 0.33));
		bsk.add_item(Bulk_quote("Elem4", 5, 8, 0.5));
		bsk.add_item(Bulk_quote("Elem5", 3.5, 15, 0.01));
	}
	bsk.total_receipt(cout);
	return 0;
}
