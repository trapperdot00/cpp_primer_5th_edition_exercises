#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::vector;
using std::endl;

int main() {
	vector<unsigned> scores(11, 0);
	unsigned grade;
	vector<unsigned>::iterator iter = scores.begin();
	while (cin >> grade) {
		if (grade <= 100) {
			++*(iter + grade / 10);
		}
	}
	for (const unsigned &r : scores) {
		cout << r << " ";
	}
	cout << endl;
	return 0;
}
