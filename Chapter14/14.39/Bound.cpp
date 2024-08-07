#include "Bound.h"

bool Bound::operator()(const std::string &s) const {
	return s.size() <= max_length;
}
