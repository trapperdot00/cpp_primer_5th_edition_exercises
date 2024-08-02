#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

using std::map;
using std::string;
using std::ifstream;
using std::getline;
using std::runtime_error;
using std::istringstream;
using std::cout;
using std::endl;

map<string, string> buildMap(ifstream &map_file) {
	map<string, string> trans_map;
	string key, value;
	while (map_file >> key && getline(map_file, value)) {
		if (value.size() > 1) {
			trans_map[key] = value.substr(1);
		} else {
			throw runtime_error("No rule for " + key);
		}
	}
	return trans_map;
}

const string &transform(const string &s, const map<string, string> &m) {
	map<string, string>::const_iterator it = m.find(s);
	if (it != m.cend()) {
		return it->second;
	} else {
		return s;
	}
}

void word_transform(ifstream &map_file, ifstream &input) {
	map<string, string> trans_map = buildMap(map_file);
	string line;
	while (getline(input, line)) {
		istringstream stream(line);
		string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword) {
				firstword = false;
			} else {
				cout << ' ';
			}
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main() {
	ifstream map_file("11.33_rules.txt"), input("11.33_source.txt");
	word_transform(map_file, input);
	return 0;
}
