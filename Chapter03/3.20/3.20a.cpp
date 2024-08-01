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
	cout << "\nSum of each pair of adjacent elemets:" << endl;
	for (decltype(ivec.size()) i = 0; i + 1 < ivec.size(); ++i) {
		cout << ivec[i] + ivec[i+1] << " ";
	}
	cout << endl;
	return 0;
}
