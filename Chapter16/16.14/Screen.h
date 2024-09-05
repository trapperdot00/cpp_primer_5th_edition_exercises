#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

template <std::string::size_type height, std::string::size_type width>
class Screen {
public:
	typedef std::string::size_type pos;
	Screen() : contents(height * width, ' ') {}
	Screen(char c) : contents(height * width, c) {}

	char get() const { return contents[cursor]; }
	char get(pos, pos) const;
	Screen &move(pos, pos);
	
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &display(std::ostream &os) { do_display(os); return *this; }
	const Screen &display(std::ostream &os) const { do_display(os); return *this; }
private:
	void do_display(std::ostream &os) const { os << contents; }

	pos cursor = 0;
	std::string contents;
};

template <std::string::size_type height, std::string::size_type width>
inline char Screen<height, width>::get(pos r, pos c) const {
	return contents[r * width + c];
}

template <std::string::size_type height, std::string::size_type width>
inline Screen<height, width> &Screen<height, width>::move(pos r, pos c) {
	cursor = r * width + c;
	return *this;
}

template <std::string::size_type height, std::string::size_type width>
inline Screen<height, width> &Screen<height, width>::set(char c) {
	contents[cursor] = c;
	return *this;
}

template <std::string::size_type height, std::string::size_type width>
inline Screen<height, width> &Screen<height, width>::set(pos r, pos c, char ch) {
	contents[r * width + c] = ch;
	return *this;
}

#endif
