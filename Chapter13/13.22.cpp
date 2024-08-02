#include <string>

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
	~HasPtr() { delete ps; }

	HasPtr(const HasPtr &obj) : ps(new std::string(*obj.ps)), i(obj.i) { }
	HasPtr &operator=(const HasPtr &rhs) {
		std::string *newp = new std::string(*rhs.ps);
		delete ps;
		ps = newp;
		i = rhs.i;
		return *this;
	}

private:
	std::string *ps;
	int i;
};

int main() {
	HasPtr a("hello");
	HasPtr b = a;
	return 0;
}
