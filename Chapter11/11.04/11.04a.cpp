#include <set>
#include <map>
#include <iostream>
#include <string>
#include <cstddef>
#include <cctype>
#include <algorithm>

using std::map;
using std::set;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::tolower;
using std::remove_if;
using std::ispunct;
using std::transform;
using std::isupper;

string lowercase(string s) {
	transform(s.begin(), s.end(), s.begin(), [](char c) { return isupper(c) ? tolower(c) : c; });
	return s;
}

string removePunct(string s) {
	s.erase(remove_if(s.begin(), s.end(), [](char c) { return ispunct(c); }), s.end());
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
