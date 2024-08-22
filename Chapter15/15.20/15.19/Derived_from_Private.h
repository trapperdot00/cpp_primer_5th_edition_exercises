#ifndef DERIVED_FROM_PRIVATE_H
#define DERIVED_FROM_PRIVATE_H

#include "Priv_Derv.h"

struct Derived_from_Private : public Priv_Derv {
	int i = 13;

	void memfcn(Base &b) { b = *this; }
};

#endif
