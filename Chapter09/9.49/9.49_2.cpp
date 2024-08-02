#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::cout;
using std::ifstream;
using std::endl;

const string ascenders("bdfhijklt"), descenders("gjpqy");

int main(int argc, char **argv) {
	if (argc < 2) return -1;
	const string filename(argv[1]);
	ifstream input(filename, ifstream::in);
	if (!input) return -2;
	string word, longestGoodWord;
	while (input >> word) {
		if (word.find_first_of(ascenders) == string::npos && word.find_first_of(descenders) == string::npos
				&& word.size() > longestGoodWord.size()) {
			longestGoodWord = word;
		}
	}
	if (longestGoodWord.empty()) {
		cout << "There are no words that contain no ascenders nor descenders in file " << filename << endl;
	} else {
		cout << "The longest word that contains no ascenders nor descenders in file " << filename << " is " << longestGoodWord << endl;
	}
	return 0;
}
