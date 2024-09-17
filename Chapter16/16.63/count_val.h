#ifndef COUNT_VAL_H
#define COUNT_VAL_H

#include <cstddef>
#include <vector>

template <typename T> std::size_t count_val(const std::vector<T> &, const T &);

template <typename T>
std::size_t count_val(const std::vector<T> &vec, const T &val) {
	std::size_t occurence = 0;
	for (const T &elem : vec)
		if (elem == val) ++occurence;
	return occurence;
}

#endif
