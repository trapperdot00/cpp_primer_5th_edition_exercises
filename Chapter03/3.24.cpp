#include <vector>
#include <iterator>
#include <iostream>

using std::vector;
using std::cin;
using std::endl;
using std::cout;

int main() {
	vector<int> numbers;
	int num = 0;
	while (numbers.size() != 10) {
		if (cin >> num) {
			numbers.push_back(num);
		}
	}
	for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
		*it *= 2;
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
