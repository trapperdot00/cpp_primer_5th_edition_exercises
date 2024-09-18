#include <bitset>
#include <cstddef>
#include <string>
#include <utility>
#include <iostream>

using std::bitset;
using std::size_t;
using std::string;
using std::cout;
using std::endl;

template <size_t N> class Test;
template <size_t N> std::ostream &operator<<(std::ostream &, const Test<N> &);

template <size_t N>
class Test {
	friend std::ostream &operator<< <N>(std::ostream &, const Test<N> &);
public:
	Test() = default;
	explicit Test(const string &s, size_t pos = 0, size_t m = string::npos,
		 char zero = '0', char one = '1') : questions(s, pos, m, zero, one) {}
	explicit Test(string &&s, size_t pos = 0, size_t m = string::npos,
		 char zero = '0', char one = '1') noexcept : questions(std::move(s), pos, m, zero, one) {}
	explicit Test(const char *cp, size_t m = size_t(-1),
		 char zero = '0', char one = '1') : questions(cp, m, zero, one) {}
	Test(unsigned long long u) : questions(u) {}
private:
	bitset<N> questions;
};

template <size_t N>
std::ostream &operator<<(std::ostream &os, const Test<N> &t) {
	return os << t.questions;
}

int main() {
	string s = "10010011";
	const char *p = "10010011";

	Test<10> t1;
	Test<10> t2(s);
	Test<10> t3(string("10010011"));
	Test<10> t4(p);
	Test<10> t5 = 147;

	cout << "t1: " << t1 << endl;
	cout << "t2: " << t2 << endl;
	cout << "t3: " << t3 << endl;
	cout << "t4: " << t4 << endl;
	cout << "t5: " << t5 << endl;

	// Since Test is a template that has a nontype parameter
	// that gets passed to bitset as an explicit template argument,
	// we only have to change the explicit template argument from 10 to 100:
	Test<100> hundredQ("101111");
	cout << "hundredQ: " << hundredQ << endl;
	return 0;
}
