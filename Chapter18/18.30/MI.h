#ifndef MI_H
#define MI_H

#include "D1.h"
#include "D2.h"

class MI : public D1, public D2 {
public:
	MI() : Base(), D1(), D2() {}
	MI(int i) : Base(i), D1(i), D2(i) {}
	MI(const MI &m) : Base(m), D1(m), D2(m) {}
};

#endif
