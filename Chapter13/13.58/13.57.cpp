#include "Foo.h"

Foo Foo::sorted() const & {
	std::cout << "const &" << std::endl;
	return Foo(*this).sorted();
}
