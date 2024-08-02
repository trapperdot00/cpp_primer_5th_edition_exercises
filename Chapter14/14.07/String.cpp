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
	char *dest = std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), newdata);
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
	std::cout << "copy constructor" << std::endl;
	std::pair<char *, char *> data = exact_alloc_copy(s.cbegin(), s.cend());
	elements = data.first;
	first_free = cap = data.second;
}
String::String(String &&s) noexcept
	: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	std::cout << "move constructor" << std::endl;
	s.elements = s.first_free = s.cap = nullptr;
}
String &String::operator=(const String &rhs) {
	std::cout << "copy-assignment operator" << std::endl;
	std::pair<char *, char *> newdata = exact_alloc_copy(rhs.cbegin(), rhs.cend());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}
String &String::operator=(String &&rhs) noexcept
{
	std::cout << "move-assignment operator" << std::endl;
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

String::~String() { free(); }

void String::push_back(char c) {
	check_full_realloc();
	alloc.construct(first_free++, c);
}

std::ostream &print(std::ostream &os, const String &s) {
	for (const char *cp = s.cbegin(); cp != s.cend(); ++cp)
		os << *cp;
	return os;
}

std::ostream &operator<<(std::ostream &os, const String &s) {
	for (const char *cp = s.cbegin(); cp != s.cend(); ++cp)
		os << *cp;
	return os;
}
