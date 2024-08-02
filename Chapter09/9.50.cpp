#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

const string numeric("+-.0123456789");

int main() {
	vector<string> numbers;
	size_t idx;
	int base = 10;
	cout << "Enter numbers to sum: ";
	for (string num; cin >> num; numbers.push_back(num)) ;
	int isum = 0;
	for (const string &s : numbers) {
		isum += stoi(s.substr(s.find_first_of(numeric)), &idx, base);
	}
	cout << "Integral sum: " << isum << "\tindex of first nonnumeric char: " << idx << '\n';
	double dsum = 0.0;
	for (const string &s : numbers) {
		dsum += stod(s.substr(s.find_first_of(numeric)), &idx);
	}
	cout << "Floating-point sum: " << dsum << "\tindex of first nonnumeric char: " << idx << endl;
	return 0;
}
