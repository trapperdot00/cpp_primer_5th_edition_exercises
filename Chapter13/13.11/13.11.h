#include <string>

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()):
		ps(new std::string(s)), i(0) { }

	// COPY CONSTRUCTOR
	HasPtr(const HasPtr& orig) : ps(new std::string(*orig.ps)), i(orig.i) {}
	
	// COPY-ASSIGNMENT OPERATOR
	HasPtr &operator=(const HasPtr &rhs) {
		delete ps;
		ps = new std::string(*rhs.ps);
		i = rhs.i;
		return *this;
	}
	
	// DESTRUCTOR
	~HasPtr() {
		delete ps;
	}

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
