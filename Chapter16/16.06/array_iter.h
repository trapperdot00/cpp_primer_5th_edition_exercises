#ifndef ARRAY_ITER_H
#define ARRAY_ITER_H

#include <cstddef>

template <typename T, std::size_t N>
T *arr_begin(T (&arr)[N]) {
	return arr;
}

template <typename T, std::size_t N>
T *arr_end(T (&arr)[N]) {
	return arr + N;
}

#endif
