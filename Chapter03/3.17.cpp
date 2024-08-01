#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

int main() {
	string word;
	vector<string> wordVec;
	while (cin >> word) {
		wordVec.push_back(word);
	}

	for (string &s : wordVec) {
		if (islower(s[0])) {
			s[0] = toupper(s[0]);
		}
	}

	for (vector<string>::size_type ind = 0; ind != wordVec.size(); ++ind) {
		if (ind != 0 && (ind % 8 == 0)) {
			cout << endl;
		}
		cout << wordVec[ind] << " ";
	}

	return 0;
}
