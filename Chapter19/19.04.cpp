#include <typeinfo>
#include <iostream>

class A {
public:
	virtual ~A() = default;
};
class B : public A {};
class C : public B {};
class D : public B, public A {};

int main() {
	A *pa = new C;
	try {
		C &rc = dynamic_cast<C &>(*pa);
	} catch (const std::bad_cast &e) {
		std::cout << e.what() << std::endl;
	}

	A *pa2 = new B;
	try {
		C &rc = dynamic_cast<C &>(*pa2);
	} catch (const std::bad_cast &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
