#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::partition;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

bool hasMoreThanFive(const string &s) {
	return s.size() >= 5;
}

int main() {
	vector<string> words;
	for (string temp; cin >> temp; words.push_back(temp)) ;
	vector<string>::const_iterator badStart = partition(words.begin(), words.end(), hasMoreThanFive);
	cout << "Good elements:\n";
	for (vector<string>::const_iterator iter = words.cbegin(); iter != badStart; ++iter) {
		cout << *iter << '\n';
	}
	cout << "\nBad elements:\n";
	for (vector<string>::const_iterator iter = badStart; iter != words.cend(); ++iter) {
		cout << *iter << '\n';
	}
	return 0;
}
