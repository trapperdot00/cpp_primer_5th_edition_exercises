#include <unordered_map>
#include <string>
#include <cstddef>
#include <iostream>
#include <utility>

using std::unordered_map;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::pair;


int main() {
	unordered_map<string, size_t> word_count;
	string word;
	while (cin >> word) {
		++word_count[word];
	}
	for (const pair<string, size_t> &p : word_count) {
		cout << p.first << ": " << p.second << endl;
	}
	return 0;
}
