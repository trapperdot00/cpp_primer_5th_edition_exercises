#include <fstream>
#include <iostream>
#include <cstddef>
#include <stdexcept>

using std::ifstream;
using std::cout;
using std::endl;
using std::size_t;
using std::runtime_error;

std::ostream &
read_and_print(std::ostream &os, const char *filename, char *sink, size_t size) {
	ifstream in(filename);
	if (!in.is_open())
		throw runtime_error("file with this filename doesn't exist!");
	while (in.getline(sink, size, '\n')) ;
	for (size_t i = 0; i != size; ++i)
		os << sink[i];
	return os;
}

int main() {
	size_t data_size = 20;
	char *const data1 = new char[data_size];
	char *const data2 = new char[data_size];
	char *const data3 = new char[data_size];
	
	cout << "file1:\n";
	read_and_print(cout, "empty.txt", data1, data_size) << endl;
	cout << "file2:\n";
	read_and_print(cout, "big.txt", data2, data_size) << endl;
	cout << "file3:\n";
	read_and_print(cout, "correct.txt", data3, data_size) << endl;
	
	delete[] data1;
	delete[] data2;
	delete[] data3;
	return 0;
}
