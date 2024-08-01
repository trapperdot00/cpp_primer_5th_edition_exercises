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
	for(int &i : numbers) {
		i *= 2;
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
