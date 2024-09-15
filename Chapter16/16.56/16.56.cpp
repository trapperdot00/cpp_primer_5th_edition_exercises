#include "errorMsg.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main() {
	int i = 100, *ip = &i;
	double d = 1.11, *dp = &d;
	string s = "str", *sp = &s;
	char ca[] = "cstr";
	const char cca[] = "ccstr";
	errorMsg(cout, i, ip, d, dp, s, sp, ca, cca) << endl;

	return 0;
}
