#ifndef PRIV_DERV_H
#define PRIV_DERV_H

#include "Base.h"

struct Priv_Derv : private Base {
	int f1() const { return prot_mem; }
};

#endif
