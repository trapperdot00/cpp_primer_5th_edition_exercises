#ifndef PUB_DERV_H
#define PUB_DERV_H

#include "Base.h"

struct Pub_Derv : public Base {
	int f() { return prot_mem; }

	void memfcn(Base &b) { b = *this; }
};

#endif
