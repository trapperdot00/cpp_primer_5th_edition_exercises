#include <iostream>

#include "Screen.h"

int main() {
	using func1 = char (Screen::*)() const;
	using func2 = char (Screen::*)(Screen::pos, Screen::pos) const;
	using func3 = Screen &(Screen::*)(Screen::pos, Screen::pos);
	using func4 = void (Screen::*)() const;
	using func5 = Screen &(Screen::*)(char);
	using func6 = Screen &(Screen::*)(Screen::pos, Screen::pos, char);
	using func7 = Screen &(Screen::*)(std::ostream &);
	using func8 = const Screen &(Screen::*)(std::ostream &) const;
	using func9 = Screen::pos Screen::* (*)();
	using func10 = void (Screen::*)(std::ostream &) const;

	func1 f1 = &Screen::get;
	func2 f2 = &Screen::get;
	func3 f3 = &Screen::move;
	func4 f4 = &Screen::some_member;
	func5 f5 = &Screen::set;
	func6 f6 = &Screen::set;
	func7 f7 = &Screen::display;
	func8 f8 = &Screen::display;
	func9 f9 = &Screen::cursor_pointer;
	
	Screen scr(7, 7, 'X');
	std::cout << (scr.*f1)() << '\n';
	std::cout << (scr.*f2)(2, 2) << '\n';

	(scr.*f3)(5, 5);
	(scr.*f4)();
	(scr.*f5)('O');
	std::cout << (scr.*f1)() << '\n';
	
	(scr.*f6)(4, 4, 'Y');
	std::cout << (scr.*f2)(4, 4) << '\n';

	(scr.*f7)(std::cout);
	std::cout << std::endl;

	(scr.*f8)(std::cout);
	std::cout << std::endl;

	const Screen::pos Screen::*p = f9();
	std::cout << scr.*p << std::endl;

	return 0;
}
