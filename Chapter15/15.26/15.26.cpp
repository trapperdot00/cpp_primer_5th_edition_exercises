#include "Quote.h"
#include "Bulk_quote.h"
#include <utility>

int main() {
	{
	Quote q1, q2("Element", 25.65), q3(q2), q4(std::move(q3));
	q1 = q2;
	q2 = std::move(q4);
	}
	std::cout << std::endl;

	{
	Bulk_quote bq1, bq2("Element", 15.99, 5, 0.10), bq3(bq2), bq4(std::move(bq3));
	bq1 = bq2;
	bq2 = std::move(bq4);
	}
	return 0;
}
