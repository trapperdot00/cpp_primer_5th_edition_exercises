#include <iostream>
#include <string>
#include <cctype>	// tolower

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	string word;
	unsigned vowelCnt = 0;
	while (cin >> word) {
		for (char c : word) {
			c = tolower(c);
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				++vowelCnt;
		}
	}
	cout << vowelCnt << " vowels in text read" << endl;
	return 0;
}
