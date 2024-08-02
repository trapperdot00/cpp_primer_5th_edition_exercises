#include <iostream>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;
using std::rand;

struct numbered {
	numbered() : mysn(rand()) {}
	
	int mysn;
};

void f(numbered s) { cout << s.mysn << endl; }

int main() {
	numbered a, b = a, c = b;

	cout << a.mysn << '\n' << b.mysn << '\n' << c.mysn << '\n' << endl;

	f(a); f(b); f(c);

	return 0;
}
