#include "Pub_Derv.h"
#include "Priv_Derv.h"
#include "Prot_Derv.h"
#include "Derived_from_Public.h"
#include "Derived_from_Private.h"
#include "Derived_from_Protected.h"

int main() {
	Base b;
	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;
	Derived_from_Public dd1;
	Derived_from_Private dd2;
	Derived_from_Protected dd3;
	
	dd2.memfcn(b);

	return 0;
}
