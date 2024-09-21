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
	template <class... Args>
	Test(Args&&... args) : questions(std::forward<Args>(args)...) {}

	void updateBit(size_t n, bool b) {
		questions.set(n, b);
	}
	// XOR returns ones for only the differing bits' positions
	// We have to flip them to get ON bits for non-differing positions
	// Now we can count them to get our score
	size_t grade(const Test &t) const {	
		return (questions ^ t.questions).flip().count();
	}

private:
	bitset<N> questions;
};

template <size_t N>
std::ostream &operator<<(std::ostream &os, const Test<N> &t) {
	return os << t.questions;
}

int main() {
	unsigned long long correctAnswers = 0x2DA;	// 1011011010
	Test<10> quiz = correctAnswers;

	Test<10> ans1("1011011010"), ans2("1000011000");
	cout << quiz << endl;
	cout << quiz.grade(ans1) << ' ' << quiz.grade(ans2) << endl;

	return 0;
}
