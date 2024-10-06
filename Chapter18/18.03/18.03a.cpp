#include <vector>
#include <fstream>
#include <stdexcept>
#include <iostream>

using std::vector;
using std::ifstream;
using std::runtime_error;
using std::cerr;
using std::endl;

void exercise(int *b, int *e) {
	int *p = nullptr;
	try {
		vector<int> v(b, e);
		p = new int[v.size()];
		ifstream in("ints");
		throw runtime_error("error");
	} catch (const runtime_error &e) {
		cerr << "caught exception, deleted array of ints" << endl;
		delete[] p;
	}
}

int main() {
	exercise(nullptr, nullptr);
	return 0;
}
