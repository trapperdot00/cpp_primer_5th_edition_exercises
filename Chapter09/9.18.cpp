#include <string>
#include <iostream>
#include <deque>

using std::string;
using std::deque;
using std::cin;
using std::cout;
using std::endl;

int main() {
	deque<string> words;
	for (string word; cin >> word; words.push_back(word)) ;
	for (deque<string>::const_iterator iter = words.cbegin(); iter != words.cend(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}
