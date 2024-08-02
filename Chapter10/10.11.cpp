#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using std::stable_sort;
using std::sort;
using std::unique;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

std::ostream &print(std::ostream &os, const vector<string> &vec) {
	for (const string &s : vec)
		cout << s << ' ';
	return os;
}

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

void elimDups(vector<string> &vec) {
	sort(vec.begin(), vec.end());
	vector<string>::iterator endUnique = unique(vec.begin(), vec.end());
	vec.erase(endUnique, vec.end());
}

int main() {
	vector<string> words;
	for (string temp; cin >> temp; words.push_back(temp)) ;
	print(cout, words) << '\n';
	elimDups(words);
	print(cout, words) << '\n';
	stable_sort(words.begin(), words.end(), isShorter);
	print(cout, words) << endl;
	return 0;
}
