#include <list>
#include <deque>
#include <iostream>

using std::list;
using std::deque;
using std::cin;
using std::cout;
using std::endl;

int main() {
	list<int> numbers;
	cout << "Enter integers: ";
	for (int num; cin >> num; numbers.push_back(num)) ;
	deque<int> evens, odds;
	for (list<int>::const_iterator iter = numbers.cbegin(); iter != numbers.cend(); ++iter) {
		if (*iter % 2) {
			odds.push_back(*iter);
		} else {
			evens.push_back(*iter);
		}
	}
	cout << "Evens: ";
	for (deque<int>::const_iterator iter = evens.cbegin(); iter != evens.cend(); ++iter)
		cout << *iter << ' ';
	cout << "\nOdds: ";
	for (deque<int>::const_iterator iter = odds.cbegin(); iter != odds.cend(); ++iter)
		cout << *iter << ' ';
	cout << endl;
	return 0;
}
