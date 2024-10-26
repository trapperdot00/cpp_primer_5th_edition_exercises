#ifndef D1_H
#define D1_H

#include "Base.h"

class D1 : virtual public Base {
public:
	D1() : Base() {}
	D1(int i) : Base(i) {}
	D1(const D1 &d) : Base(d) {}
};

#endif
