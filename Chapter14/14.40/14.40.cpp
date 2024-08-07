#include "ShorterString.h"
#include "SizeComp.h"
#include "PrintString.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

using std::vector;
using std::string;
using std::stable_sort;
using std::find_if;
using std::for_each;
using std::size_t;
using std::sort;
using std::unique;
using std::cout;
using std::endl;
using std::cin;
using std::istream_iterator;

string make_plural(size_t ctr, const string &word, const string &ending) {
	return (ctr > 1) ? word + ending : word;
}

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	vector<string>::iterator end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), ShorterString());
	vector<string>::iterator wc = find_if(words.begin(), words.end(), SizeComp(sz));
	size_t count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
	for_each(wc, words.end(), PrintString(cout, ' '));
	cout << endl;
}

int main() {
	cout << "Enter words: ";
	istream_iterator<string> in(cin), eof;
	vector<string> svec(in, eof);
	biggies(svec, 7);
	return 0;
}
