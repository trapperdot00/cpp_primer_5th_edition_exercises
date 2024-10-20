#include "Exercise.h"

int ivar = 0;
using Exercise::ivar;	// error: target of using declaration conflicts with declaration already in scope
using Exercise::dvar;
using Exercise::limit;
void manip() {
	double dvar = 3.1416;
	int iobj = limit + 1;
	++ivar;
	++::ivar;
}
