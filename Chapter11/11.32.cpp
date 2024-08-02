#include <map>
#include <iostream>
#include <string>
#include <set>

using std::set;
using std::map;
using std::multimap;
using std::string;
using std::cout;
using std::endl;
using std::cin;

std::ostream &print(std::ostream &os, const map<string, set<string>> &m) {
	map<string, set<string>>::const_iterator it = m.cbegin();
	while (it != m.cend()) {
		os << it->first << ":";
		for (set<string>::const_iterator sit = it->second.cbegin(); sit != it->second.cend(); ++sit) {
			os << ' ' << *sit;
		}
		os << endl;
		++it;
	}
	return os;
}

void orderCopy(const multimap<string, string> &lhs, map<string, set<string>> &rhs) {
	multimap<string, string>::const_iterator mm_it = lhs.cbegin();
	while (mm_it != lhs.cend()) {
		rhs[mm_it->first].insert(mm_it->second);
		++mm_it;
	}
}

int main() {
	multimap<string, string> authors = {{"A", "bookAC"},{"B", "bookBB"},{"C", "bookC"},{"A", "bookAB"},{"D", "bookD"},{"B", "bookBA"},{"E", "bookE"},{"A", "bookAA"},{"F", "bookF"},{"G", "bookGB"},{"G", "bookGA"},{"G", "bookGC"}};
	map<string, set<string>> orderedAuth;
	orderCopy(authors, orderedAuth);
	print(cout, orderedAuth);
	return 0;
}
