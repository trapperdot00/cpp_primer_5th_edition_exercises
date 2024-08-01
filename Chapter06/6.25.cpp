#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(int argc, char **argv) {
	string concatenated;
	for (int i = 0; i != argc; ++i) {
		concatenated += argv[i];
		concatenated += " ";
	}
	cout << concatenated << endl;
	return 0;
}
