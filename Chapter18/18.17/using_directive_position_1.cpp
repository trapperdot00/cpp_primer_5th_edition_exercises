#include "Exercise.h"

int ivar = 0;
using namespace Exercise;
void manip() {
	double dvar = 3.1416;
	int iobj = limit + 1;
	++ivar;					// error: reference to ivar is ambiguous
	++::ivar;
}
