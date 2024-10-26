#ifndef D2_H
#define D2_H

#include "Base.h"

class D2 : virtual public Base {
public:
	D2() : Base() {}
	D2(int i) : Base(i) {}
	D2(const D2 &d) : Base(d) {}
};

#endif
