#include <utility>
#include <vector>
#include <sstream>
#include <iostream>

using std::pair;
using std::make_pair;
using std::vector;
using std::string;
using std::istringstream;
using std::getline;
using std::cin;
using std::cout;
using std::endl;

void print(const vector<pair<string, int>> &vec) {
	for (const pair<string, int> &p : vec) {
		cout << p.first << " : " << p.second << "\n";
	}
}

int main() {
	vector<pair<string, int>> pairs;
	string line;
	while (getline(cin, line)) {
		istringstream stream(line);
		string s;
		int i;
		stream >> s >> i;
		pair<string, int> p = make_pair(s, i);
		pairs.push_back(p);
	}
	print(pairs);
	return 0;
}
