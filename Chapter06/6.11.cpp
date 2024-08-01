#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void reset(int &i) {
	i = 0;
}

int main() {
	int num;
	cout << "Enter number: ";
	cin >> num;
	reset(num);
	cout << num << endl;
	return 0;
}
