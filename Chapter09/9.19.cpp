#include <string>
#include <list>
#include <iostream>

using std::string;
using std::list;
using std::cin;
using std::cout;
using std::endl;

int main() {
	list<string> words;	// 1st change: list type
	for (string word; cin >> word; words.push_back(word)) ;
	for (list<string>::const_iterator iter = words.cbegin(); iter != words.cend(); ++iter) {	// 2nd change: iterator type
		cout << *iter << ' ';
	}
	cout << endl;
	return 0;
}
