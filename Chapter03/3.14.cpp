#include <iostream>
#include <vector>

using std::vector;
using std::cin;

int main() {
	vector<int> ivec;
	int num;
	while (cin >> num) {
		ivec.push_back(num);
	}
}
