#ifndef MEMORY_H
#define MEMORY_H

#include <cstdlib>
#include <cstddef>
#include <stdexcept>
#include <iostream>

void *operator new(std::size_t);
void operator delete(void *) noexcept;

#endif
