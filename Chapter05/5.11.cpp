#include <iostream>
#include <string>
#include <cctype>	// tolower

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	unsigned spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
	string s;
	while (getline(cin, s)) {
		for (char ch : s) {
			switch (tolower(ch)) {
				case 'a':
					++aCnt;
					break;
				case 'e':
					++eCnt;
					break;
				case 'i':
					++iCnt;
					break;
				case 'o':
					++oCnt;
					break;
				case 'u':
					++uCnt;
					break;

				case ' ':
					++spaceCnt;
					break;
				case '\t':
					++tabCnt;
					break;
				default:
					break;
			}
		}
		++newlineCnt;
	}
	cout << "Number of vowel a: " << aCnt << '\n'
		 << "Number of vowel e: " << eCnt << '\n'
		 << "Number of vowel i: " << iCnt << '\n'
		 << "Number of vowel o: " << oCnt << '\n'
		 << "Number of vowel u: " << uCnt << '\n'
		 << "Number of spaces: " << spaceCnt << '\n'
		 << "Number of tabs: " << tabCnt << '\n'
		 << "Number of newlines: " << newlineCnt << endl;
	return 0;
}
