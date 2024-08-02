#include <vector>
#include <numeric>
#include <iostream>

using std::vector;
using std::accumulate;
using std::cout;
using std::endl;

int main() {
	vector<double> dvec{3.5, 4.5, 6.5, 7.5, 8.5};
	for (const double &d : dvec) {
		cout << d << " ";
	}
	double acc = accumulate(dvec.cbegin(), dvec.cend(), 0);	// uses 0 (int) as a variable to collect the sum into, return truncated
	double realAcc = accumulate(dvec.cbegin(), dvec.cend(), 0.0);	// double as collector
	cout << '\n' << acc << '\n' << realAcc << endl;

	return 0;
}
