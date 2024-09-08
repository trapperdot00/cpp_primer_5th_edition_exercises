#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H

#include <iostream>

class DebugDelete {
public:
	DebugDelete(std::ostream &s = std::cerr) : os(s) {}
	DebugDelete(const DebugDelete &d) : os(d.os) {}
	DebugDelete(DebugDelete &&d) noexcept : os(d.os) {}
	DebugDelete &operator=(const DebugDelete &rhs) {
		return *this;
	}
	DebugDelete &operator=(DebugDelete &&rhs) noexcept {
		return *this;
	}
	template <typename T>
	void operator()(T *p) const {
		os << "deleting unique_ptr" << std::endl;
		delete p;
	}
private:
	std::ostream &os;
};

#endif
