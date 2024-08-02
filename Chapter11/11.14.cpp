#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <utility>
#include <vector>

using std::map;
using std::string;
using std::vector;
using std::pair;
using std::getline;
using std::cin;
using std::istringstream;
using std::endl;
using std::cout;


void readMap(map<string, vector<pair<string, string>>> &m) {
	string line;
	while (getline(cin, line)) {
		istringstream stream(line);
		string famLastname;
		stream >> famLastname;
		vector<pair<string, string>> &childrenNames = m[famLastname];
		string childname, birthday;
		while (stream >> childname >> birthday) {
			pair<string, string> p = {childname, birthday};
			childrenNames.push_back(p);
		}
	}
}

void printMap(const map<string, vector<pair<string, string>>> &m) {
	for (const auto &p : m) {
		cout << p.first << " : ";
		for (const pair<string, string> &s : p.second) {
			cout << s.first << '-' << s.second << ' ';
		}
		cout << '\n';
	}
}

int main() {
	map<string, vector<pair<string, string>>> nameMap;
	readMap(nameMap);
	printMap(nameMap);
	return 0;
}
