#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

using std::unordered_map;
using std::string;
using std::ifstream;
using std::getline;
using std::runtime_error;
using std::istringstream;
using std::cout;
using std::endl;

unordered_map<string, string> transMap(ifstream &rules) {
	unordered_map<string, string> trans_map;
	string key, value;
	while (rules >> key && getline(rules, value)) {
		if (value.size() > 1) {
			trans_map[key] = value.substr(1);
		} else {
			throw runtime_error("No rule for " + key);
		}
	}
	return trans_map;
}

const string &transform(const string &s, const unordered_map<string, string> &m) {
	unordered_map<string, string>::const_iterator it = m.find(s);
	if (it != m.cend()) {
		return it->second;
	} else {
		return s;
	}
}

void word_transform(ifstream &rules, ifstream &input) {
	unordered_map<string, string> trans_map = transMap(rules);
	string line;
	while (getline(input, line)) {
		istringstream stream(line);
		string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				cout << ' ';
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main() {
	ifstream rules("11.38_rules.txt"), source("11.38_source.txt");
	word_transform(rules, source);
	return 0;
}
