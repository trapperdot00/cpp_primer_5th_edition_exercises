#include "Foo.h"

Foo Foo::sorted() const & {
	std::cout << "const &" << std::endl;
	Foo ret(*this);
	return ret.sorted();
}
