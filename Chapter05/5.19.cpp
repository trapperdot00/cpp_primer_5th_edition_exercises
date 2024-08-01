#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	do {
		string s1, s2;
		cout << "Enter two strings: ";
		if (cin >> s1 >> s2) {
			if (s1 == s2)
				cout << "The two strings are identical" << endl;
			else if (s1 > s2) 
				cout << "The first string is larger" << endl;
			else
				cout << "The second string is larger" << endl;	
		}
	} while (cin);
	return 0;
}
