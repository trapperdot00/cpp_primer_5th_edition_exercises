#ifndef DERIVED_FROM_PROTECTED_H
#define DERIVED_FROM_PROTECTED_H

#include "Prot_Derv.h"

struct Derived_from_Protected : public Prot_Derv {
	int use_base() { return prot_mem; }
};

#endif
