#include "Pub_Derv.h"
#include "Priv_Derv.h"
#include "Prot_Derv.h"
#include "Derived_from_Public.h"
#include "Derived_from_Private.h"
#include "Derived_from_Protected.h"

int main() {
	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;
	Derived_from_Public dd1;
	Derived_from_Private dd2;
	Derived_from_Protected dd3;

	Base *p = &d1;
	p = &d2;
	p = &d3;
	p = &dd1;
	p = &dd2;
	p = &dd3;
	return 0;
}
