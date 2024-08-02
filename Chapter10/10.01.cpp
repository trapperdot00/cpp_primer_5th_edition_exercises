#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main() {
	vector<int> numbers;
	cout << "Enter elements to put in vector: ";
	for (int temp; cin >> temp; numbers.push_back(temp)) ;	// read into vector
	vector<int> occured;
	cout << '\n';
	for (const int &num : numbers) {
		if (find(occured.cbegin(), occured.cend(), num) == occured.cend()) {
			cout << num << " occurs " << count(numbers.cbegin(), numbers.cend(), num) << " times. "  << endl;
			occured.push_back(num);
		}
	}
	cout << "\nNumber of elements: " << numbers.size() << "\nNumber of unique elements: " << occured.size() << endl;
	return 0;
}
