#include <vector>
#include <list>
#include <iostream>
#include <string>

using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::string;

int main() {
	list<const char *> lc = {"aa", "bb-b", "cc", "dddd", "eeeeeee"};
	vector<string> vec;
	vec.assign(lc.cbegin(), lc.cend());
	for (const string &s : vec)
		cout << s << " ";
	cout << endl;
	return 0;
}
