#include <iostream>
#include <cctype>	// tolower

using std::cout;
using std::cin;
using std::endl;

int main() {
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;
	char ch, prevCh;
	while (cin >> ch) {
		switch (ch) {
			case 'a': case 'A':
				++aCnt;
				break;
			case 'e': case 'E':
				++eCnt;
				break;
			case 'i':
				if (prevCh == 'f')
					++fiCnt;
			case 'I':
				++iCnt;
				break;
			case 'o': case 'O':
				++oCnt;
				break;
			case 'u': case 'U':
				++uCnt;
				break;
			case 'f':
				if (prevCh == 'f')
					++ffCnt;
				break;
			case 'l':
				if (prevCh == 'f')
					++flCnt;
				break;
			default:
				break;
		}
		prevCh = ch;
	}
	cout << "Number of vowel a: " << aCnt << '\n'
		 << "Number of vowel e: " << eCnt << '\n'
		 << "Number of vowel i: " << iCnt << '\n'
		 << "Number of vowel o: " << oCnt << '\n'
		 << "Number of vowel u: " << uCnt << '\n'
		 << "Number of sequence ff: " << ffCnt << '\n'
		 << "Number of sequence fl: " << flCnt << '\n'
		 << "Number of sequence fi: " << fiCnt << endl;
	return 0;
}
