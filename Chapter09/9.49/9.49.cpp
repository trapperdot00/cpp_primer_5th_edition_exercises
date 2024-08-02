#include <string>
#include <iostream>
#include <fstream>

using std::ifstream;
using std::string;
using std::cout;
using std::endl;

const string ascenders("bdfhijklt"),
	  		 descenders("gjpqy"), ascenders_descenders(ascenders + descenders);

bool hasNoAscender(const string &word) {
	string::size_type index = 0, count = 0;
	while ((index = word.find_first_not_of(ascenders, index)) != string::npos) {
		++count;
		++index;
	}
	if (count == word.size())
		return true;
	return false;
}

bool hasNoDescender(const string &word) {
	string::size_type index = 0, count = 0;
	while ((index = word.find_first_not_of(descenders, index)) != string::npos) {
		++count;
		++index;
	}
	if (count == word.size())
		return true;
	return false;
}

bool hasNeither(const string &word) {
	if (hasNoAscender(word) && hasNoDescender(word))
		return true;
	return false;
}

// using this
bool hasNeitherBetter(const string &word) {
	if (word.find_first_of(ascenders_descenders) == string::npos) {
		return true;
	} else {
		return false;
	}
}

int main(int argc, char **argv) {
	if (argc < 2) return -1;
	string filename(argv[1]);
	ifstream input(filename, ifstream::in);
	if (!input) return -2;
	string word, longestGoodWord;
	while (input >> word) {
		if (hasNeitherBetter(word) && word.size() > longestGoodWord.size()) {
			longestGoodWord = word;
		}
	}
	if (!longestGoodWord.empty())
		cout << "The longest word inside " << filename << " that contains no ascenders and descenders is " << longestGoodWord << endl;
	else
		cout << "There are no words that contain no ascenders and descenders in " << filename << endl;
	return 0;
}
