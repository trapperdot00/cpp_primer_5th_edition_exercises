#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main() {
	vector<int> ivec;

	for (int num = 0; cin >> num; ivec.push_back(num)) {}
	cout << "Elements in vector:" << endl;
	for (const int &ri : ivec) {
		cout << ri << " ";
	}
	cout << "\nSums:" << endl;
	for (decltype(ivec.size()) i = 0; i != ivec.size() / 2; ++i) {
		cout << ivec[i] + ivec[ivec.size() - i - 1] << " ";
	}
	cout << endl;
	return 0;
}
