#include <map>
#include <set>
#include <string>
#include <iostream>
#include <cstddef>
#include <utility>

using std::map;
using std::set;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::pair;
using std::make_pair;

std::istream &read(std::istream &is, map<string, size_t> &m, const set<string> &ex) {
	string word;
	while (is >> word) {
		if (ex.find(word) == ex.end()) {
			pair<map<string, size_t>::iterator, bool> ret = m.insert(make_pair(word, 1));
			if (!ret.second)	// if the insert failed (word already exists as key)
				++ret.first->second;
		}
	}
	return is;
}

std::ostream &print(std::ostream &os, const map<string, size_t> &m) {
	map<string, size_t>::const_iterator it = m.cbegin();
	while (it != m.cend()) {
		os << it->first << ": " << it->second << '\n';
		++it;
	}
	return os;
}

int main() {
	map<string, size_t> word_count;
	set<string> exclude = {"the", "but", "and", "or", "an", "a",
						   "The", "But", "And", "Or", "An", "A"};
	read(cin, word_count, exclude);
	print(cout, word_count);
	return 0;
}
