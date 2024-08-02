#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Test {
	friend void swap(Test &, Test &);
	friend std::ostream &print(std::ostream &, const Test &);
public:
	Test(const std::string &s) : text(new std::string(s)), i(0) {}
	Test(const Test &t) : text(new std::string(*t.text)), i(0) {}
	Test &operator=(Test rhs) {
		swap(*this, rhs);
		return *this;
	}
	~Test() { delete text; }
	bool operator<(const Test &t) const { return text < t.text; }
private:
	std::string *text;
	int i;
};

inline void swap(Test &lhs, Test &rhs) {
	std::cout << "swapping " << *lhs.text << " with " << *rhs.text << std::endl;
	using std::swap;
	swap(lhs.text, rhs.text);
	swap(lhs.i, rhs.i);
}

std::ostream &print(std::ostream &os, const Test &t) {
	os << *t.text << '\n';
	return os;
}

using std::cout;
using std::vector;
using std::string;
using std::sort;
using std::for_each;
using std::endl;

int main() {
	Test a("a"), b("b");
	vector<Test> vec{b, a};
	for_each(vec.cbegin(), vec.cend(), [](const Test &t){print(cout, t);});
	cout << "sort: " << endl;
	sort(vec.begin(), vec.end());
	for_each(vec.cbegin(), vec.cend(), [](const Test &t){print(cout, t);});
	return 0;
}
