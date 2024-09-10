#ifndef SUM_H
#define SUM_H

template <typename T1, typename T2>
auto sum(const T1 &a, const T2 &b) -> decltype(a + b) {
	return a + b;
}

#endif
