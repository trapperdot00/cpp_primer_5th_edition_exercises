#include <cmath>
#include <iostream>

using std::cout;
using std::endl;
using std::uppercase;
using std::nouppercase;
using std::scientific;
using std::fixed;
using std::hexfloat;
using std::defaultfloat;
using std::sqrt;

int main() {
	cout << "default format: " << 100 * sqrt(2) << '\n'
		 << "scientific: " << scientific << 100 * sqrt(2) << '\n'
		 << "fixed decimal: " << fixed << 100 * sqrt(2) << '\n'
		 << "hexadecimal: " << hexfloat << uppercase << 100 * sqrt(2) << '\n'
		 << "use defaults: " << defaultfloat << nouppercase << 100 * sqrt(2) << endl;
	return 0;
}
