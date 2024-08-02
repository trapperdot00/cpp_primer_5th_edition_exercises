#include <map>
#include <iostream>
#include <string>

using std::map;
using std::cout;
using std::endl;
using std::string;

std::ostream &print(std::ostream &os, const map<string, int> &m) {
	map<string, int>::const_iterator it = m.cbegin();
	while (it != m.cend()) {
		os << it->first << ": " << it->second << '\n';
		++it;
	}
	return os;
} 

int main() {
	map<string, int> m = {{"A", 1}, {"B", 5}, {"C", 12}, {"D", 55}, {"E", 6}};
	map<string, int>::iterator map_iter = m.begin();
	map_iter->second = 0;
	print(cout, m);
	return 0;
}
