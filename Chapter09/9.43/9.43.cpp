#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

string &replaceAbbr(string &s, const string &oldVal, const string &newVal) {
	const string::size_type oldSize = oldVal.size(),
							newSize = newVal.size();
	string::iterator iter = s.begin();
	string::size_type index = 0;
	while (iter != s.end()) {
		if (s.substr(index, oldSize) == oldVal) {
			iter = s.erase(iter, iter + oldSize);
			iter = s.insert(iter, newVal.begin(), newVal.end());
			iter += newSize;
			index += newSize;
		} else {
			++iter;
			++index;
		}
	}
	return s;
}

int main() {
	string s("tho tho tho thru thru thru");
	cout << s << '\n' << replaceAbbr(s, "tho", "though") << '\n' << replaceAbbr(s, "thru", "through") << endl;
	return 0;
}
