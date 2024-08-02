#include <string>

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()):
		ps(new std::string(s)), i(0) { }

	HasPtr(const HasPtr& orig) : ps(new std::string(*orig.ps)), i(orig.i) {}
	
	void nullStr() {
		delete ps;
		ps = nullptr;
	}
	const std::string& get() const {
		static std::string empty;
		return ps ? *ps : empty;
	}

private:
	std::string *ps;
	int i;
};
