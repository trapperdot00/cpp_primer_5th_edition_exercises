#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <utility>

using std::multimap;
using std::string;
using std::vector;
using std::getline;
using std::istringstream;
using std::pair;
using std::make_pair;
using std::cin;
using std::cout;
using std::endl;

std::istream &read(std::istream &is, multimap<string, vector<string>> &mm) {
	string line;
	while (getline(is, line)) {
		istringstream stream(line);
		string lastname;
		stream >> lastname;
		string childname;
		vector<string> children;
		while (stream >> childname) {
			children.push_back(childname);
		}
		pair<string, vector<string>> p = make_pair(lastname, children);
		mm.insert(p);
	}
	return is;
}

std::ostream &print(std::ostream &os, const multimap<string, vector<string>> &mm) {
	for (multimap<string, vector<string>>::const_iterator it = mm.cbegin(); it != mm.cend(); ++it) {
		os << it->first << ": ";
		for (vector<string>::const_iterator childIt = it->second.cbegin(); childIt != it->second.cend(); ++childIt) {
			os << *childIt << ' ';
		}
		os << '\n';
	}
	return os;
}

int main() {
	multimap<string, vector<string>> fam;
	read(cin, fam);
	print(cout, fam);
	return 0;
}
