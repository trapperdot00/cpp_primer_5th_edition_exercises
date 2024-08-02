#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <cctype>

using std::map;
using std::string;
using std::vector;
using std::cin;
using std::find;
using std::cout;
using std::endl;
using std::tolower;
using std::isupper;
using std::transform;
using std::remove_if;
using std::ispunct;

string &nopunct(string &s) {
	s.erase(remove_if(s.begin(), s.end(), [](char c) { return ispunct(c); }), s.end());
	return s;
}

string &lower(string &s) {
	transform(s.begin(), s.end(), s.begin(), [](char c){ return isupper(c) ? tolower(c) : c;});
	return s;
}

int main() {
	map<string, size_t> word_count;
	vector<string> exclude = {"the", "but", "and", "or", "an", "a",
							  "The", "But", "And", "Or", "An", "A"};
	string word;
	while (cin >> word) {
		lower(nopunct(word));
		if (find(exclude.cbegin(), exclude.cend(), word) == exclude.cend()) {
			++word_count[word];
		}
	}
	for (const auto &e : word_count) {
		cout << e.first << " occurs " << e.second << ((e.second > 1) ? " times." : " time.") << endl;
	}
	return 0;
}
