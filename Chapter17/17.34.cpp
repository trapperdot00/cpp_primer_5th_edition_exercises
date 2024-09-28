#include <iomanip>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::boolalpha;
using std::noboolalpha;
using std::showbase;
using std::noshowbase;
using std::showpoint;
using std::noshowpoint;
using std::showpos;
using std::noshowpos;
using std::uppercase;
using std::nouppercase;
using std::dec;
using std::hex;
using std::oct;
using std::left;
using std::right;
using std::internal;
using std::fixed;
using std::scientific;
using std::hexfloat;
using std::defaultfloat;
using std::unitbuf;
using std::nounitbuf;
using std::skipws;
using std::noskipws;
using std::flush;
using std::ends;
using std::endl;
using std::setfill;
using std::setprecision;
using std::setw;
using std::setbase;

int main() {
	bool t = true, f = false;
	int i = 1234, i2 = -1234;
	double d = 1.23456789123, d2 = 1.0;

	cout << boolalpha << t << '\t' << f << endl;
	cout << noboolalpha << t << '\t' << f << endl;

	cout << showbase << hex << i << '\t'
		 << oct << i << '\t' << dec << i
		 << noshowbase << endl;

	cout << showpoint << d << '\t' << d2 << '\n'
		 << setprecision(12) << d << '\t' << d2 << '\n'
		 << noshowpoint << d << '\t' << d2 << endl;
	cout.precision(6);

	cout << showpos << i << '\t' << i2 << endl
		 << noshowpos;

	cout << uppercase << hex << d << nouppercase << dec << endl;

	cout << left << setw(24) << i << "|\n"
		 << setw(24) << i2 << "|\n"
		 << setw(24) << d << "|\n"
		 << setw(24) << d2 << '|' << right << endl;

	cout << right << setw(24) << i << '|' << endl;

	cout << internal << setw(24) << i2 << "|\n"
		 << setw(24) << d << '|' << right << endl;

	cout << left << fixed << setw(24) << d << d2 << '\n'
		 << scientific << setw(24) << d << d2 << '\n'
		 << hexfloat << setw(24) << d << d2 << '\n'
		 << defaultfloat << setw(24) << d << d2 << endl;

	cout << unitbuf << "unitbuf" << " on" << nounitbuf << ", now off" << endl;

	cout << flush;

	char p[4] = {'e', 'n', 'd', 's'};	// not null-terminated
	cout << p << ends << endl;

	cout << setfill('#') << setw(24) << i2 << setfill(' ') << endl;

	cout << setbase(8) << i << ' ' << i2 << setbase(10) << endl;

	cout << "enter something: ";

	string text;
	cin >> noskipws;
	for (char c; cin >> c; text += c) ;
	cin >> skipws;
	cout << text;

	return 0;
}
