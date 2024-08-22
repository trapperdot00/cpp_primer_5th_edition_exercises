#ifndef PROT_DERV_H
#define PROT_DERV_H

#include "Base.h"

struct Prot_Derv : protected Base {
	int func() const { return prot_mem; }
};

#endif
