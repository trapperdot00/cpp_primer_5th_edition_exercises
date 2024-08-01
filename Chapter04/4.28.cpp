#include <iostream>

using std::cout;
using std::endl;

int main() {
	cout << "bool: " << sizeof(bool) << " bytes" << endl;
	cout << "char: " << sizeof(char) << " bytes" << endl;
	cout << "wchar_t: " << sizeof(wchar_t) << " bytes" << endl;
	cout << "char16_t: " << sizeof(char16_t) << " bytes" << endl;
	cout << "char32_t: " << sizeof(char32_t) << " bytes" << endl;
	cout << "short: " << sizeof(short) << " bytes" << endl;
	cout << "int: " << sizeof(int) << " bytes" << endl;
	cout << "long: " << sizeof(long) << " bytes" << endl;
	cout << "long long: " << sizeof(long long) << " bytes" << endl;
	cout << "float: " << sizeof(float) << " bytes" << endl;
	cout << "double: " << sizeof(double) << " bytes" << endl;
	cout << "long double: " << sizeof(long double) << " bytes" << endl;
	int i, *p = &i;
	cout << "pointer: " << sizeof(p) << " bytes" << endl;
	return 0;


}
