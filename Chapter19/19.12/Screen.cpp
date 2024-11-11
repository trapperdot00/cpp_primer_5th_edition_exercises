#include "Screen.h"

Window_mgr::Window_mgr() : screens{Screen(24, 80, ' ')} {}

void Window_mgr::clear(ScreenIndex i) {
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}

void Screen::some_member() const {
	++access_ctr;
}
