#include "StrVec.h"

void StrVec::push_back(const std::string &s) {
	chk_n_alloc();	// ensure that there is room for another element
	// construct a copy of s in the element to which first_free points
	alloc.construct(first_free++, s);
}

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
	// allocate space to hold as many elements as in the range
	// data denotes the first allocated from the range
	// allocate function takes a size
	std::string *data = alloc.allocate(e - b);
	// initialize and return a pair constructed from data and
	// the value returned by uninitialized_copy
	return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free() {
		// may not pass deallocate a 0 pointer; if elements is 0, there's no work to do
	if (elements) {
		// destroy the old elements in reverse order
		for (std::string *p = first_free; p != elements; /*empty*/ )
			alloc.destroy(--p);
		std::for_each(elements, first_free, [this](std::string &s){ alloc.destroy(&s);});

		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const std::initializer_list<std::string> &il) {
	std::pair<std::string *, std::string *> data = alloc_n_copy(il.begin(), il.end());
	elements = data.first;
	first_free = cap = data.second;
}

StrVec::StrVec(const StrVec &s) {
	// call alloc_n_copy to allocate exactly as many elements as in s
	std::pair<std::string *, std::string *> newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

// MOVE CONSTRUCTOR
StrVec::StrVec(StrVec &&s) noexcept
	: elements(s.elements), first_free(s.first_free), cap(s.cap) 
{
	s.elements = s.first_free = s.cap = nullptr;
}
// MOVE-ASSIGNMENT OPERATOR
StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs) {
	// calls alloc_n_copy to allocate exactly as many elements as in rhs
	std::pair<std::string *, std::string *> newdata = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}

void StrVec::reallocate() {
	// we'll allocate space for twice as many elements as the current size
	std::size_t newcapacity = size() ? 2 * size() : 1;
	// allocate new memory
	std::string *newdata = alloc.allocate(newcapacity);
	// move the data from the old memory to the new
	std::string *dest = newdata;	// points to the next free position in the new array
	std::string *elem = elements;	// points to the next element in the old array
	for (std::size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();	// free the old space once we've moved the elements
	// update our data structure to point to the new elements
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::reserve(std::size_t n) {
	if (n > capacity()) {
		std::size_t oldsize = size();
		std::string *newdata = alloc.allocate(n);
		std::uninitialized_copy(elements, first_free, newdata);
		free();
		elements = newdata;
		first_free = elements + oldsize;
		cap = elements + n;
	}
}

void StrVec::resize(std::size_t n) { resize(n, ""); }

void StrVec::resize(std::size_t n, const std::string &s) {
	if (n < size()) {
		while (first_free != elements + n)
			alloc.destroy(--first_free);
	} else if (n > size()) {
		reserve(n);
		while (first_free != elements + n)
			alloc.construct(first_free++, s);
	}
}

bool operator==(const StrVec &lhs, const StrVec &rhs) {
	return lhs.elements == rhs.elements &&
			lhs.first_free == rhs.first_free &&
			lhs.cap == rhs.cap;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs) {
	return !(lhs == rhs);
}
