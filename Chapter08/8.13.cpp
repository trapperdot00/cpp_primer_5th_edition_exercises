#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using std::ifstream;
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

int main(int argc, char **argv) {
	if (argc < 2) return -1;
	ifstream inputFile(argv[1]);
	if (inputFile.fail()) return -1;
	string line, word;
	vector<PersonInfo> people;
	while (getline(inputFile, line)) {
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
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
