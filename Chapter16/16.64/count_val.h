#ifndef COUNT_VAL_H
#define COUNT_VAL_H

#include <cstddef>
#include <vector>
#include <cstring>

template <typename T> std::size_t count_val(const std::vector<T> &, const T);

template <typename T>
std::size_t count_val(const std::vector<T> &vec, const T val) {
	std::size_t occurence = 0;
	for (const T &elem : vec)
		if (elem == val) ++occurence;
	return occurence;
}

template <>
std::size_t count_val(const std::vector<const char *> &vec, const char * const val) {
	std::size_t occurence = 0;
	for (const char * const &p : vec)
		if (std::strcmp(p, val) == 0) ++occurence;
	return occurence;
}

#endif
