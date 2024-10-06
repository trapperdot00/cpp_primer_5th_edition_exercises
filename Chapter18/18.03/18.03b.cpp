#include <vector>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <memory>

using std::vector;
using std::ifstream;
using std::runtime_error;
using std::cerr;
using std::endl;
using std::unique_ptr;

void exercise(int *b, int *e) {
	vector<int> v(b, e);
	unique_ptr<int[]> p(new int[v.size()]);
	ifstream in("ints");
	throw runtime_error("error");
}

int main() {
	try {
		exercise(nullptr, nullptr);
	} catch (const runtime_error &e) {
		cerr << "caught exception" << endl;
	}
	return 0;
}
