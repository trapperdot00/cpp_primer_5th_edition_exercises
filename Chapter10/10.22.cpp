#include <functional>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::vector;
using std::for_each;
using std::string;
using std::bind;
using namespace std::placeholders;
using std::cout;
using std::endl;
using std::count_if;

bool check_size(const string &s, string::size_type sz) {
	return s.size() <= sz;
}

int main() {
	vector<string> vec = {"auto", "mama", "hailer", "killers", "ninjas", "apple", "pear", "rocket", "au", "hatefully", "worldpeace", "hammer", "sources"};
	for_each(vec.cbegin(), vec.cend(), [](const string &s) -> void {cout << s << ' ';});
	cout << endl;
	vector<string>::size_type count = count_if(vec.cbegin(), vec.cend(), bind(check_size, _1, 6));
	cout << count << endl;
	return 0;
}
