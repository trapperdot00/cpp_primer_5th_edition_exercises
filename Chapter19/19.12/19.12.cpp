#include <iostream>

#include "Screen.h"

int main() {
	// Can read or write the cursor, can be used only on non-const Screens
	Screen::pos Screen::*rw_cursorp = Screen::cursor_pointer();

	// Can only read the cursor, can be used on any Screen
	const Screen::pos Screen::*r_cursorp = Screen::const_cursor_pointer();

	Screen screen1(100, 200);
	screen1.move(10, 2);

	const Screen screen2(80, 50);

	std::cout << screen1.*rw_cursorp << std::endl;
	std::cout << screen2.*r_cursorp << std::endl;
	return 0;
}
