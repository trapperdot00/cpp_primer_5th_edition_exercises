#include "PersonInfo.h"
#include "valid.h"

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <regex>

using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::regex;
using std::sregex_iterator;

vector<PersonInfo>
readPeople(std::istream &is, const regex &r) {
	vector<PersonInfo> ret;
	for (string line; getline(is, line) ;) {
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		string phones = line.substr(info.name.size());
		for (sregex_iterator it(phones.cbegin(), phones.cend(), r), end;
				it != end; ++it) {
			info.phones.push_back(it->str());
		}
		ret.push_back(info);
	}
	return ret;
}

std::ostream &
printPeople(std::ostream &os, const vector<PersonInfo> &pvec, const regex &r) {
	for (const PersonInfo &person : pvec) {
		os << person.name << " ";
		string phones;
		for (const string &phone : person.phones) {
			for (sregex_iterator it(phone.cbegin(), phone.cend(), r), end;
				 it != end; ++it) {
				if (valid(*it))
					os << "\n\tvalid:\t\t" << it->str() << " ";
				else
					os << "\n\tinvalid:\t" << it->str() << " ";
			}
		}
		os << endl;
	}
	return os;
}

int main(int argc, char **argv) {
	ifstream inputFile(argv[1]);
	if (inputFile.fail()) return -1;

//	regex r("(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})");
//	regex r("(\\()?(\\d{3})(\\))?([-.]|[ ]+)?(\\d{3})([-.]|[ ]+)?(\\d{4})");
	regex r("(\\()?(\\d{3})(\\))?([-.]|[ ]+)?(\\d{3})([-.]|[ ]+)?(\\d{4})");

	vector<PersonInfo> people = readPeople(inputFile, r);
	printPeople(cout, people, r);
	
	return 0;
}
