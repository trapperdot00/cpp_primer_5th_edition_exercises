#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;
using std::istream_iterator;
using std::cin;
using std::cout;
using std::endl;
using std::bind;
using namespace std::placeholders;
using std::not_equal_to;

int main() {
	cout << "Enter words: ";
	istream_iterator<string> in(cin), eof;
	vector<string> svec(in, eof);

	vector<string>::iterator it = find_if(svec.begin(), svec.end(), bind(not_equal_to<string>(), _1, "pooh"));
	
	if (it != svec.end())
		cout << *it << " is the first string that is not equal to \"pooh\"" << endl;
	return 0;
}
