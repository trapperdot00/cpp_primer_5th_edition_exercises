#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using std::map;
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::istringstream;

std::ostream &print(std::ostream &os, const map<string, vector<string>> &m) {
	for (const auto &e : m) {
		cout << e.first << ": ";
		for (const string &name : e.second) {
			cout << name << " ";
		}
		cout << endl;
	}
	return os;
}

int main() {
	map<string, vector<string>> lname_children;
	string line;
	while (getline(cin, line)) {
		istringstream stream(line);
		string family, child;
		stream >> family;
		vector<string> &children = lname_children[family];
		while (stream >> child) {
			children.push_back(child);
		}
	}
	
	print(cout, lname_children);
	return 0;
}
