#include <string>
#include <map>
#include <vector>
#include <random>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <utility>
#include <memory>
#include <cstddef>
#include <ctime>
#include <algorithm>

using std::string;
using std::map;
using std::vector;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::ifstream;
using std::istringstream;
using std::getline;
using std::cout;
using std::endl;
using std::runtime_error;
using std::invalid_argument;
using std::isspace;
using std::isalnum;
using std::pair;
using std::shared_ptr;
using std::make_shared;
using std::size_t;
using std::partition;

// class that keeps the random engine's and the distribution's state
// and all objects have the same static members used for the
// random number generation
class MakeshiftRandom {
public:
	size_t operator()() const {
		return up->operator()(*ep);
	}
	void range(size_t low, size_t high) const {
		if (low < high)
			up = make_shared<uniform_int_distribution<size_t>>(low, high);
		else
			throw invalid_argument("invalid range");
	}
	void seed(size_t s) const {
		ep->seed(s);
	}
private:
	static shared_ptr<default_random_engine> ep;
	static shared_ptr<uniform_int_distribution<size_t>> up;
};

shared_ptr<default_random_engine>
MakeshiftRandom::ep(make_shared<default_random_engine>());

shared_ptr<uniform_int_distribution<size_t>>
MakeshiftRandom::up(make_shared<uniform_int_distribution<size_t>>());

map<string, vector<string>> buildMap(ifstream &map_file) {
	map<string, vector<string>> trans_map;
	string key, values;
	// iterate line-by-line, first read is the key, remainder are the values
	while (map_file >> key && getline(map_file, values)) {
		if (values.size() > 1) {		
			trans_map[key];		// add key to map
			values = values.substr(1);	// remove whitespace from the beginning
			// range of iterators denoting a value
			string::const_iterator from = values.cbegin(), to = values.cbegin();
			// loop to add the values to the vector
			while (to != values.cend()) {
				// cout << *from << ' ' << *to << endl;
				if (*to == ';') {
					trans_map.at(key).emplace_back(from, to);
					from = ++to;
					while (from != values.cend() && isspace(*from))
						++from;
				} else {
					++to;
				}
			}
			trans_map.at(key).emplace_back(from, to);
		} else {
			throw runtime_error("No rule for " + key);
		}
	}
	return trans_map;
}

const string &transform(const string &s, const map<string, vector<string>> &m) {
	if (m.find(s) == m.cend() || m.at(s).empty())
		return s;
	else {
		MakeshiftRandom r;
		r.range(1, m.at(s).size());
		size_t index = r();
		return m.at(s)[index - 1];
	}
}

void word_transform(ifstream &map_file, ifstream &input) {
	// remove these characters for checking matches
	static string remove_chars = ".,-:;\"";
	map<string, vector<string>> trans_map = buildMap(map_file);
	for (string line; getline(input, line); ) {
		istringstream stream(line);
		string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				cout << ' ';
			// remove all invalid characters from word, like commas or dots
			string::iterator bad = partition(word.begin(), word.end(),
						[](char c){return remove_chars.find(c) == string::npos;});
			word.erase(bad, word.end());
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

// print elements of a map<string, vector<string>>
std::ostream &debug_print(std::ostream &os, const map<string, vector<string>> &m) {
	for (map<string, vector<string>>::const_iterator it = m.cbegin(); it != m.cend(); ++it) {
		os << it->first << ":\t";
		for (vector<string>::const_iterator vals = it->second.cbegin(); vals != it->second.cend(); ++vals)
			os << *vals << '|';
		os << endl;
	}
	return os;
}

int main() {
	MakeshiftRandom r;
	r.seed(time(0));
	ifstream map_file("rules.txt"), input("text.txt");
	word_transform(map_file, input);
	return 0;
}
