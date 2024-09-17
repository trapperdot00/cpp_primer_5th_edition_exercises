#include "Sales_data.h"
#include <tuple>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>
#include <fstream>
#include <numeric>

using std::tuple;
using std::get;
using std::make_tuple;
using std::vector;
using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::cin;
using std::accumulate;
using std::equal_range;
using std::pair;
using std::ifstream;

template <typename T1, typename T2, typename T3>
struct Threes {
	Threes(const T1 &t1, const T2 &t2, const T3 &t3)
			: first(t1), second(t2), third(t3) {}

	T1 first;
	T2 second;
	T3 third;
};

template <typename T1, typename T2, typename T3>
Threes<T1, T2, T3>
makeThrees(const T1 &t1, const T2 &t2, const T3 &t3) {
	return Threes<T1, T2, T3>(t1, t2, t3);
}

bool compareIsbn(const Sales_data&, const Sales_data&);

typedef Threes<vector<Sales_data>::size_type,
			   vector<Sales_data>::const_iterator,
			   vector<Sales_data>::const_iterator>
		SalesThrees;

vector<SalesThrees>
findBook(const vector<vector<Sales_data>> &files, const string &book) {
	vector<SalesThrees> ret;
	for (vector<vector<Sales_data>>::const_iterator it = files.cbegin();
			it != files.cend(); ++it) {
		pair<vector<Sales_data>::const_iterator,
			 vector<Sales_data>::const_iterator>
				found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
			ret.push_back(makeThrees(
						static_cast<vector<Sales_data>::size_type>(it - files.cbegin()),
					   	found.first, found.second));
	}
	return ret;	
}

void reportResults(std::istream &in, std::ostream &os,
				const vector<vector<Sales_data>> &files) {
	string s;
	while (in >> s) {
		vector<SalesThrees> trans = findBook(files, s);
		if (trans.empty()) {
			cout << s << " not found in any stores" << endl;
			continue;
		}
		for (const SalesThrees &store : trans) {
			os << "store: " << store.first << " sales: "
			   << accumulate(store.second, store.third, Sales_data(s)) << endl;
		}
	}
}

// Function template to generate a vector of Sales_data objects
// from a reference to a input stream
template <typename T>
vector<Sales_data> generateVec(T &file) {
	vector<Sales_data> ret;
	for (Sales_data temp; file >> temp; ret.push_back(temp)) ;
	return ret;
}

// Variadic function template to call the other overload
// and generate a vector of vectors of Sales_data
// returned by the overload
// calls the overloaded function with each input stream reference
template <typename... Args>
vector<vector<Sales_data>> generateVec(Args&... files) {
	vector<vector<Sales_data>> ret{generateVec(files)...};
	return ret;
}

int main() {
	ifstream store0("sales0.txt"), store1("sales1.txt"), store2("sales2.txt");
	if (store0.is_open() && store1.is_open() && store2.is_open())
		reportResults(cin, cout, generateVec(store0, store1, store2));
	else
		cerr << "missing input files!" << endl;
	return 0;
}
