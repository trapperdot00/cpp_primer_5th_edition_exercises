#ifndef STRING_H
#define STRING_H

#include <memory>
#include <cstddef>
#include <utility>
#include <cstring>
#include <iostream>

class String {

	friend std::ostream &print(std::ostream &, const String &);	
public:
	String();
	String(const char *);
	String(const String &);
	String(String &&) noexcept;					// move constructor
	String &operator=(const String &);
	String &operator=(String &&) noexcept;		// move-assignment operator
	~String();

	void push_back(char);

	std::size_t size() const { return first_free - elements; }
	std::size_t capacity() const { return cap - elements; }
	char *begin() { return elements; }
	const char *cbegin() const { return elements; }
	char *end() { return first_free; }
	const char *cend() const { return first_free; }
private:
	static std::allocator<char> alloc;
	
	void reallocate();
	std::pair<char *, char *> exact_alloc_copy(const char *, const char *) const;
	void check_full_realloc() { if (size() == capacity()) reallocate(); }
	void free() const;


	char *elements;
	char *first_free;
	char *cap;
};

#endif
