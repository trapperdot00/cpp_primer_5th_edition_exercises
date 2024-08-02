#include <map>
#include <iostream>
#include <cstddef>

using std::string;
using std::size_t;
using std::map;
using std::cout;
using std::cin;
using std::endl;

std::istream &read(std::istream &is, map<string, size_t> &m) {
	string word;
	while (is >> word) {
		++m[word];
	}
	return is;
}

std::ostream &print(std::ostream &os, const map<string, size_t> &m) {
	map<string, size_t>::const_iterator map_it = m.cbegin();
	while (map_it != m.cend()) {
		os << map_it->first << " occurs " << map_it->second << " times" << endl;
		++map_it;
	}
	return os;
}

int main() {
	map<string, size_t> word_count;
	read(cin, word_count);
	print(cout, word_count);
	return 0;
}
