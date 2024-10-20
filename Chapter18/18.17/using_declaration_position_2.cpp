#include "Exercise.h"

int ivar = 0;
void manip() {
	using Exercise::ivar;
	using Exercise::dvar;
	using Exercise::limit;
	double dvar = 3.1416;	// error: declaration conflicts with target of using declaration already in scope
	int iobj = limit + 1;
	++ivar;
	++::ivar;
}
