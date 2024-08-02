#include <algorithm>
#include <list>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>

using std::string;
using std::cout;
using std::endl;
using std::list;
using std::fill_n;
using std::cin;
using std::back_inserter;
using std::istringstream;
using std::getline;

int main() {
	list<int> numbers;
	string line;
	while (getline(cin, line)) {
		istringstream stream(line);
		auto backI = back_inserter(numbers);
		for (int temp; stream >> temp; *backI = temp) ;
	}
	for (const int &i : numbers) {
		cout << i << ' ';
	}
	cout << '\n';
	fill_n(numbers.begin(), numbers.size(), 0);
	for (const int & i : numbers) {
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}
