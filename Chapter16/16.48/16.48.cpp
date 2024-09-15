#include "debug_rep.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Out {
	friend std::ostream &operator<<(std::ostream &, const Out &);
public:
	Out(const std::string &s = "") : text(s) {}
private:
	std::string text;
};
std::ostream &operator<<(std::ostream &os, const Out &o) {
	return os << o.text;
}

int main() {
	Out obj("object");
	cout << debug_rep(obj) << "\n\n";

	int *vp = nullptr;
	cout << debug_rep(vp) << "\n\n";

	int i = 5, *ip = &i;
	cout << debug_rep(ip) << "\n\n";

	string s = "string";
	cout << debug_rep(s) << "\n\n";

	char ca1[] = "char array";
	cout << debug_rep(ca1) << "\n\n";

	const char ca2[] = "const char array";
	cout << debug_rep(ca2) << endl;

	return 0;
}
