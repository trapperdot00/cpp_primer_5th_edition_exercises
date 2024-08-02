#include "String.h"

std::allocator<char> String::alloc;

std::pair<char *, char *> String::exact_alloc_copy(const char *b, const char *e) const {
	char *data = alloc.allocate(e - b);
	return std::make_pair(data, std::uninitialized_copy(b, e, data));
}

void String::free() const {
	for (const char *p = first_free; p != elements; )
		alloc.destroy(--p);
	alloc.deallocate(elements, cap - elements);
}

void String::reallocate() {
	std::size_t newcapacity = size() ? 2 * size() : 1;
	char *newdata = alloc.allocate(newcapacity);
	char *dest = newdata;
	char *elem = elements;
	for (std::size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, *elem++);
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

String::String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
String::String(const char *cp) {
	std::size_t strsize = std::strlen(cp);
	std::pair<char *, char *> data = exact_alloc_copy(cp, cp + strsize);
	elements = data.first;
	first_free = cap = data.second;
}
String::String(const String &s) {
	std::pair<char *, char *> data = exact_alloc_copy(s.cbegin(), s.cend());
	elements = data.first;
	first_free = cap = data.second;
}
String &String::operator=(const String &rhs) {
	std::pair<char *, char *> newdata = exact_alloc_copy(rhs.cbegin(), rhs.cend());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}
String::~String() { free(); }

void String::push_back(char c) {
	check_full_realloc();
	alloc.construct(first_free++, c);
}

std::ostream &print(std::ostream &os, const String &s) {
	std::size_t length = s.size();
	char *cp = new char[length + 1];
	const char *elem = s.elements;
	char *dest = cp;
	for (std::size_t i = 0; i != length; ++i) {
		*dest++ = *elem++;
	}
	cp[length] = '\0';
	os << cp;
	delete[] cp;
	return os;
}
