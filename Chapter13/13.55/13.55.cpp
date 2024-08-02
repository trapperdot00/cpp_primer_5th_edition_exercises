#include "StrBlob.h"

int main() {
	StrBlob s;
	s.push_back("what");
	std::string a = "aa";
	s.push_back(a);
	return 0;
}
