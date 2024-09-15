#ifndef ERRORMSG_H
#define ERRORMSG_H

#include "print.h"
#include "debug_rep.h"
#include <iostream>

template <typename... Args>
std::ostream &errorMsg(std::ostream &os, const Args&... rest) {
	return print(os, debug_rep(rest)...);
}

#endif
