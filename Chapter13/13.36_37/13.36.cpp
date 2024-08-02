#include "Folder.h"
#include "Message.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
	Folder fld1("fontos"), fld2("bejovo"), fld3("olvasott"), fld4("kuka"), fld5("spam");
	Message msg1("fontosolvasott"), msg2("viccesscammer"), msg3("indianscammer"), msg4("reklam"), msg5("rendeles");

	msg1.save(fld1);
	msg1.save(fld3);
	msg2.save(fld3);
	msg2.save(fld5);
	msg3.save(fld4);
	msg3.save(fld5);
	msg4.save(fld2);
	msg4.save(fld3);
	msg4.save(fld4);
	msg5.save(fld1);
	msg5.save(fld2);
	msg5.save(fld3);

	print(cout, fld1) << endl;
	print(cout, fld2) << endl;
	print(cout, fld3) << endl;
	print(cout, fld4) << endl;
	print(cout, fld5) << endl;

	return 0;
}
