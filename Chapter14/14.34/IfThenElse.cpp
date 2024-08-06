#include "IfThenElse.h"

int IfThenElse::operator()(bool b, int i, int j) const {
	return b ? i : j;
}
