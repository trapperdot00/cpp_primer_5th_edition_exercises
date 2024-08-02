#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::vector;
using std::string;
using std::sort;
using std::unique;
using std::cout;
using std::endl;
using std::cin;

std::ostream &print(std::ostream &os, const vector<string> &vec) {
	for (const string &elem : vec) {
		os << elem << ' ';
	}
	return os;
}

void elimDups(vector<string> &vec) {
	sort(vec.begin(), vec.end());
	print(cout, vec) << '\n';
	vector<string>::iterator end_of_unique_elements = unique(vec.begin(), vec.end());
	print(cout, vec) << '\t' << vec.size() << '\n';
	vec.erase(end_of_unique_elements, vec.end());
}

int main() {
	vector<string> words;
	for (string temp; cin >> temp; words.push_back(temp)) ;
	print(cout, words) << '\n';
	elimDups(words);
	print(cout, words) << '\t' << words.size() << endl;
	return 0;
}
