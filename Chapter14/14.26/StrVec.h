#ifndef STRVEC_H
#define STRVEC_H

#include <string>
#include <memory> 
#include <cstddef>
#include <utility>
#include <initializer_list>
#include <algorithm>

class StrVec {
	friend bool operator==(const StrVec &, const StrVec &);
	friend bool operator!=(const StrVec &, const StrVec &);

	friend bool operator<(const StrVec &, const StrVec &);
	friend bool operator>(const StrVec &, const StrVec &);
	friend bool operator<=(const StrVec &, const StrVec &);
	friend bool operator>=(const StrVec &, const StrVec &);
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
	StrVec(const std::initializer_list<std::string> &);
	StrVec(const StrVec &);
	StrVec(StrVec &&) noexcept;					// move constructor
	StrVec &operator=(const StrVec &);
	StrVec &operator=(StrVec &&) noexcept;		// move-assignment operator
	StrVec &operator=(const std::initializer_list<std::string> &);
	~StrVec();

	std::string &operator[](std::size_t n) { return elements[n]; }
	const std::string &operator[](std::size_t n) const { return elements[n]; }

	void push_back(const std::string &);

	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }

	std::size_t size() const { return first_free - elements; }
	std::size_t capacity() const { return cap - elements; }

	// allocate space for at least n elements
	void reserve(std::size_t);
	// resize so that it has n elements. if n < size(), the excess elements are discarded
	// if new elements must be added, they are value initialized
	void resize(std::size_t);
	// resize to have n elements. any elements added have value s
	void resize(std::size_t, const std::string &);

private:

	std::allocator<std::string> alloc;
	void chk_n_alloc()
		{ if (size() == capacity()) reallocate(); }
	std::pair<std::string *, std::string *> alloc_n_copy
			(const std::string *, const std::string *);
	void free();
	void reallocate();

	std::string *elements;
	std::string *first_free;
	std::string *cap;
};

bool operator==(const StrVec &, const StrVec &);
bool operator!=(const StrVec &, const StrVec &);

bool operator<(const StrVec &, const StrVec &);
bool operator>(const StrVec &, const StrVec &);
bool operator<=(const StrVec &, const StrVec &);
bool operator>=(const StrVec &, const StrVec &);

#endif
