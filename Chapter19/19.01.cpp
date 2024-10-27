#include <cstdlib>
#include <cstddef>
#include <stdexcept>
#include <iostream>

void *operator new(std::size_t size) {
	std::clog << "new" << std::endl;
	if (void *mem = std::malloc(size))
		return mem;
	else
		throw std::bad_alloc();
}

void operator delete(void *mem) noexcept {
	std::clog << "delete" << std::endl;
	std::free(mem);
}

int main() {
	int *p = new int(6);
	delete p;
	return 0;
}
