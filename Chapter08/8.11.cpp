#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using std::cin;
using std::istringstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main() {
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while (getline(cin, line)) {
		PersonInfo info;
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
		record.clear();
	}
	for (const PersonInfo &elem : people) {
		cout << elem.name << " ";
		for (const string &phone : elem.phones) {
			cout << phone << " ";
		}
		cout << endl;
	}
	return 0;
}
