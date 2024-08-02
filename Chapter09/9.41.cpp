#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<char> cv{'t', 'e', 's', 't'};
	string s(cv.begin(), cv.end());
	cout << s << endl;
	return 0;
}
