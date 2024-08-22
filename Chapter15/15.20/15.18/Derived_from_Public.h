#ifndef DERIVED_FROM_PUBLIC_H
#define DERIVED_FROM_PUBLIC_H

#include "Pub_Derv.h"

struct Derived_from_Public : public Pub_Derv {
	int use_base() { return prot_mem; }
};

#endif
