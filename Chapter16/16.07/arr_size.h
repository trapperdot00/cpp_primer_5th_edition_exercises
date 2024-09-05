#ifndef ARR_SIZE_H
#define ARR_SIZE_H

#include <cstddef>

template <typename T, std::size_t N>
constexpr std::size_t arr_size(const T (&)[N]) {
	return N;
}

#endif
