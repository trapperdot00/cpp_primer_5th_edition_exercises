#include "Exercise.h"

int ivar = 0;
void manip() {
	using namespace Exercise;
	double dvar = 3.1416;
	int iobj = limit + 1;
	++ivar;					// error: reference to ivar is ambiguous
	++::ivar;
}
