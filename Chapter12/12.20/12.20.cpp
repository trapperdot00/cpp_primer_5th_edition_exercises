#include "StrBlob.h"
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::getline;
using std::string;

int main() {
	ifstream input("12.20.txt");
	StrBlob str;
	
	for (string temp; getline(input, temp); str.push_back(temp)) ;
	
	StrBlobPtr sPtr = str.begin();
	StrBlob::size_type sz = str.size();

	for (StrBlob::size_type i = 0; i != sz; ++i) {
		cout << sPtr.deref() << endl;
		sPtr.incr();
	}
	
	return 0;
}
