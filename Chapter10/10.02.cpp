#include <algorithm>
#include <list>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::list;

int main() {
	list<string> words;
	cout << "Enter elements to put in list: ";
	for (string temp; cin >> temp; words.push_back(temp)) ;
	list<string> occured;
	cout << '\n';
	for (const string &val : words) {
		if (find(occured.cbegin(), occured.cend(), val) == occured.cend()) {
			cout << val << " occurs " << count(words.cbegin(), words.cend(), val) << " times." << endl;
			occured.push_back(val);
		}
	}
	cout << "\nNumber of elements: " << words.size() << "\nNumber of unique elements: " << occured.size() << endl;
	return 0;
}
