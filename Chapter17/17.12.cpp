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

	void updateBit(size_t n, bool b) {
		questions.set(n, b);
	}
private:
	bitset<N> questions;
};

template <size_t N>
std::ostream &operator<<(std::ostream &os, const Test<N> &t) {
	return os << t.questions;
}

int main() {
	Test<8> bseq;
	cout << bseq << endl;
	for (size_t i = 0; i != 8; ++i) {
		bseq.updateBit(i, true);
		cout << bseq << endl;
	}
	for (size_t i = 8; i != 0; --i) {
		bseq.updateBit(i - 1, false);
		cout << bseq << endl;
	}
	for (size_t i = 8; i != 0; --i) {
		bseq.updateBit(i - 1, true);
		cout << bseq << endl;
	}
	for (size_t i = 0; i != 8; ++i) {
		bseq.updateBit(i, false);
		cout << bseq << endl;
	}

	return 0;
}
