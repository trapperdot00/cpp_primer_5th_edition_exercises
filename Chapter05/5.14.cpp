#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main() {
	unsigned cnt = 0, maxCnt = 0;
	string curr, prev, max;
	while (cin >> curr) {
		if (curr == prev) {
			++cnt;
		} else {
			if (maxCnt < cnt) {
				max = prev;
				maxCnt = cnt;
			}
			cnt = 1;
		}
		prev = curr;
	}
	if (cnt > maxCnt) {
		maxCnt = cnt;
		max = curr;
	}
	if (maxCnt < 2) {
		cout << "There were no repeating words." << endl;
	} else {
		cout << "The most repeated word was " << max << " which occured " << maxCnt << " times." << endl;
	}
	return 0;
}
