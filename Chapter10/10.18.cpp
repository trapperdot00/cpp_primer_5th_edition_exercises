#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstddef>

using std::istringstream;
using std::vector;
using std::string;
using std::sort;
using std::stable_sort;
using std::unique;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::partition;
using std::for_each;

string make_plural(size_t ctr, const string &word, const string &ending) {
	return (ctr > 1) ? word + ending : word;
}

void elimDups(vector<string> &vec) {
	// sort vector's elements alphabetically
	sort(vec.begin(), vec.end());

	// move duplicated elements to the end of the vector, and get iterator to the first duplicate, to the end of the unique sequence
	vector<string>::iterator endOfUnique = unique(vec.begin(), vec.end());

	// erase the duplicated elements from back of the vector
	vec.erase(endOfUnique, vec.end());
}

void biggies(vector<string> &vec, vector<string>::size_type sz) {
	elimDups(vec);

	// sort vector's elements by the elements' sizes, while keeping the previous alphabetical sorting
	stable_sort(vec.begin(), vec.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });

	// find first element in vector that has at least the size of the parameter sz
	vector<string>::iterator firstCorrect = partition(vec.begin(), vec.end(), [sz](const string &s) -> bool { return (s.size() < sz) ? true : false; });
	
	// get count of elements that have a minimum of sz size
	vector<string>::difference_type count = vec.end() - firstCorrect;

	// print this nonsense
	cout << count << ' ' << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
	
	// print each of the correct sized elements
	for_each(firstCorrect, vec.end(), [](const string &s) { cout << s << ' '; });

	// newline because whynot?
	cout << endl;
}

int main() {
	vector<string> words;
	size_t min;
	cout << "Enter minimum size to look for in words: ";
	
	// if read into min fails, then print a new line and quit with failure
	if (!(cin >> min)) { cout << endl; return -1; }
	string temp;
	cout << "Enter words: ";

	// read lines into temp, if the reading fails, while exits
	while (getline(cin, temp)) {
		
		// copy the read line into a stringstream that we can read from
		istringstream stream(temp);
		string word;

		// read the elements (separated by whitespace) from the stream, and insert into the back of the vector
		while (stream >> word)
			words.push_back(word);
	}
	biggies(words, min);
	
	return 0;
}
