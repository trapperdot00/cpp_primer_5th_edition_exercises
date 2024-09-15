#ifndef FLIP_H
#define FLIP_H

#include <utility>	// std::forward

template <typename Func, typename T1, typename T2>
void flip(Func f, T1 &&t1, T2 &&t2) {
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

#endif
