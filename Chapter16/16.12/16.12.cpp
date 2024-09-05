#include "Blob.h"

#include <string>
#include <iostream>

using StrBlob = Blob<std::string>;
using StrBlobPtr = BlobPtr<std::string>;
using ConstStrBlobPtr = ConstBlobPtr<std::string>;

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main() {

	// StrBlob is an alias to Blob<string>
	StrBlob sb{"a", "b", "c", "d", "e", "f", "g", "h"};
	for (ConstStrBlobPtr p = sb.cbegin(); p != sb.cend(); cout << *p++ << " ") ; // Printing with iterators
	cout << endl;
	for (StrBlob::size_type i = 0; i != sb.size(); ++i) {	// Printing via subscription
		cout << sb[i] << " ";
	}
	cout << endl;

	// Reading integers into the back of a Blob<int>, then printing them from the Blob instance
	Blob<int> ib;
	for (int i; cin >> i; ib.push_back(i)) ;	// Reading
	for (ConstBlobPtr p = ib.cbegin(); p != ib.cend(); cout << *p++ << " " ) ; // Printing
	cout << endl;

	Blob<int> ib2{1,2,3,4,5,6,7,8};
	if (ib == ib2) {
		cout << "ib and ib2 are equal" << endl;
	} else if (ib != ib2) {
		cout << "ib and ib2 are not equal" << endl;
	}

	while (!ib2.empty()) {
		cout << ib2.front() << " ... " <<  ib2.back() << endl;
		ib2.pop_back();
	}
	for (BlobPtr<int> p = ib.begin(); p < ib.end(); ++p) {
		*p *= 2;
		cout << *p << " ";
	}
	cout << endl;
	return 0;
}
