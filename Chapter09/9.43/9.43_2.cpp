#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

string &replaceAbbr(string &s, const string &oldVal, const string &newVal) {
	const string::size_type oldSize = oldVal.size(),
		  					newSize = newVal.size();
	string::iterator iter = s.begin();
	while (iter != s.end()) {
		string subS(iter, iter + oldSize);
		//cout << *iter << ' ';
		if (subS == oldVal) {
			iter = s.erase(iter, iter + oldSize);
			iter = s.insert(iter, newVal.begin(), newVal.end());
			iter += newSize;
		} else {
			++iter;
		}
	}
	return s;
}

void doTheStuff(string &s) {
	vector<string> oldS{"tho", "thru"}, newS{"though", "through"};
	for (vector<string>::size_type index = 0; index != 2; ++index)
		cout << replaceAbbr(s, oldS[index], newS[index]) << endl;
}

int main() {
	string s;
	while (getline(cin , s))
		doTheStuff(s);
	return 0;
}
