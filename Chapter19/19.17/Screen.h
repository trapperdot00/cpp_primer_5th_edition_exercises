#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <cstddef>
#include <vector>

class Screen;

class Window_mgr {
public:
	Window_mgr();
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
private:
	std::vector<Screen> screens;
};

class Screen {
	friend void Window_mgr::clear(ScreenIndex);
public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

	char get() const { return contents[cursor]; }
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	void some_member() const;
	
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &display(std::ostream &os)
		{ do_display(os); return *this; }
	const Screen &display(std::ostream &os) const 
		{ do_display(os); return *this; }

	static pos Screen::*cursor_pointer() { return &Screen::cursor; }
	static const pos Screen::*const_cursor_pointer() { return &Screen::cursor; }

private:
	void do_display(std::ostream &os) const { os << contents; }

	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

	mutable std::size_t access_ctr = 0;
};

inline Screen &Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

char Screen::get(pos r, pos c) const {
	pos row = r * width;
	return contents[row + c];
}

inline Screen &Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
	contents[r * width + col] = ch;
	return *this;
}

#endif
