#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strcat;

int main() {
	char *concatenated = new char[15];
	strcat(concatenated, "Hello, ");
	strcat(concatenated, " World!");
	cout << concatenated << endl;
	delete[] concatenated;
	return 0;
}
