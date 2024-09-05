#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <cstddef>

template <typename T, std::size_t N>
void print(const T (&arr)[N]) {
	for (const T &elem : arr)
		std::cout << elem << std::endl;
}

#endif
