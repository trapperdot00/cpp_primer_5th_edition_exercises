#include <set>
#include <map>
#include <iostream>
#include <string>
#include <cstddef>
#include <cctype>

using std::map;
using std::set;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::tolower;
using std::ispunct;

string lowercase(string s) {
	for (char &c : s) {
		c = tolower(c);
	}
	return s;
}

string removePunct(string s) {
	string::iterator iter = s.begin();
	while (iter != s.end()) {
		cout << *iter << ' ';
		if (ispunct(*iter)) {
			iter = s.erase(iter);
		} else {
			++iter;
		}
	}
	cout << s << endl;
	return s;
}

int main() {
	map<string, size_t> word_count;
	set<string> exclude { "the", "but", "and", "or", "an", "a"};
	string word;
	while (cin >> word) {
		word = removePunct(word);
		word = lowercase(word);
		if (exclude.find(word) == exclude.end()) {
			++word_count[word];
		}
	}
	for (const auto &w : word_count) {
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times." : " time.") << endl;
	}
	return 0;
}
