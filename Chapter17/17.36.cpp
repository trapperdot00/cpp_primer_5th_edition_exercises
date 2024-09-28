#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::endl;
using std::scientific;
using std::fixed;
using std::hexfloat;
using std::defaultfloat;
using std::uppercase;
using std::nouppercase;
using std::setw;
using std::right;
using std::left;
using std::sqrt;

int main() {
	int wcnt = 20;
	cout << left << setw(wcnt) << "default format: " << setw(wcnt) << right << 100 * sqrt(2) << '\n'
		 << left << setw(wcnt) << "scientific: " << scientific << setw(wcnt) << right << 100 * sqrt(2) << '\n'
		 << left << setw(wcnt) << "fixed decimal: " << fixed << setw(wcnt) << right << 100 * sqrt(2) << '\n'
		 << left << setw(wcnt) << "hexadecimal: " << hexfloat << uppercase << setw(wcnt) << right << 100 * sqrt(2) << '\n'
		 << left << setw(wcnt) << "use defaults: " << defaultfloat << nouppercase << setw(wcnt) << right << 100 * sqrt(2) << endl;

   	return 0;
}
