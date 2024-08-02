#include "Sales_data.h"
using std::cout;
using std::endl;
using std::cin;
int main() {
	cout << "data1:\n";
	Sales_data data1;
	cout << "\ndata2:\n";
	Sales_data data2("aa");
	cout << "\ndata3:\n";
	Sales_data data3("aaa", 3, 4);
	cout << "\ndata4:\n";
	Sales_data data4(cin);
	return 0;
}
