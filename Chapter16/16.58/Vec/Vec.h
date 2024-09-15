#ifndef VEC_H
#define VEC_H

#include <string>
#include <memory>
#include <cstddef>
#include <utility>
#include <initializer_list>
#include <algorithm>

template <typename T> class Vec {
public:
	Vec();
	Vec(std::initializer_list<T>);
	Vec(const Vec &);
	Vec(Vec &&) noexcept;
	Vec &operator=(const Vec &);
	Vec &operator=(Vec &&) noexcept;
	Vec &operator=(std::initializer_list<T>);
	~Vec();

	T &operator[](std::size_t);
	const T &operator[](std::size_t) const;

	void push_back(const T &);
	void push_back(T &&);
	template <class... Args> void emplace_back(Args&&...);
	
	T *begin();
	T *end();
	const T *begin() const;
	const T *end() const;
	const T *cbegin() const;
	const T *cend() const;

	std::size_t size() const;
	std::size_t capacity() const;

	void reserve(std::size_t);
	void resize(std::size_t);
	void resize(std::size_t, const T &);
	void resize(std::size_t, T &&);
private:
	static std::allocator<T> alloc;
	void chk_n_alloc();
	std::pair<T *, T *> alloc_n_copy(const T *, const T *);
	void free();
	void reallocate();

	T *elements;
	T *first_free;
	T *cap;
};

template <typename T> std::allocator<T> Vec<T>::alloc;

template <typename T>
Vec<T>::Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

template <typename T>
Vec<T>::Vec(std::initializer_list<T> il) {
	std::pair<T *, T *> data = alloc_n_copy(il.begin(), il.end());
	elements = data.first;
	first_free = cap = data.second;
}

template <typename T>
Vec<T>::Vec(const Vec &v) {
	std::pair<T *, T *> data = alloc_n_copy(v.begin(), v.end());
	elements = data.first;
	first_free = cap = data.second;
}

template <typename T>
Vec<T>::Vec(Vec &&v) noexcept
: elements(v.elements), first_free(v.first_free), cap(v.cap) {
	v.elements = v.first_free = v.cap = nullptr;
}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs) {
	std::pair<T *, T *> data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template <typename T>
Vec<T> &Vec<T>::operator=(Vec &&rhs) noexcept {
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

template <typename T>
Vec<T> &Vec<T>::operator=(std::initializer_list<T> il) {
	std::pair<T *, T *> data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template <typename T> Vec<T>::~Vec() { free(); }

template <typename T>
inline T &Vec<T>::operator[](std::size_t n) { return elements[n]; }

template <typename T>
inline const T &Vec<T>::operator[](std::size_t n) const { return elements[n]; }

template <typename T>
void Vec<T>::push_back(const T &elem) {
	chk_n_alloc();
	alloc.construct(first_free++, elem);
}

template <typename T>
void Vec<T>::push_back(T &&elem) {
	chk_n_alloc();
	alloc.construct(first_free++, std::move(elem));
}

template <typename T>
template <class... Args>
inline
void Vec<T>::emplace_back(Args&&... args) {
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}

template <typename T>
inline T *Vec<T>::begin() { return elements; }

template <typename T>
inline T *Vec<T>::end() { return first_free; }

template <typename T>
inline const T *Vec<T>::begin() const { return cbegin(); }

template <typename T>
inline const T *Vec<T>::end() const { return cend(); }

template <typename T>
inline const T *Vec<T>::cbegin() const { return elements; }

template <typename T>
inline const T *Vec<T>::cend() const { return first_free; }

template <typename T>
inline std::size_t Vec<T>::size() const { return first_free - elements; }

template <typename T>
inline std::size_t Vec<T>::capacity() const { return cap - elements; }

template <typename T>
void Vec<T>::reserve(std::size_t n) {
	if (n > capacity()) {
		std::size_t old_size = size();
		T *data = alloc.allocate(n);
		std::uninitialized_copy(elements, first_free, data);
		free();
		elements = data;
		first_free = elements + old_size;
		cap = elements + n;
	}
}

template <typename T>
void Vec<T>::resize(std::size_t n) {
	resize(n, T());
}
template <typename T>
void Vec<T>::resize(std::size_t n, const T &val) {
	if (n < size()) {
		while (first_free != elements + n)
			alloc.destroy(--first_free);
	} else if (n > size()) {
		reserve(n);
		while (first_free != elements + n)
			alloc.construct(first_free++, val);
	}
}
template <typename T>
void Vec<T>::resize(std::size_t n, T &&val) {
	if (n < size()) {
		while (first_free != elements + n)
			alloc.destroy(--first_free);
	} else if (n > size()) {
		reserve(n);
		while (first_free != elements + n)
			alloc.construct(first_free++, std::move(val));
	}
}

template <typename T>
void Vec<T>::chk_n_alloc() { if (size() == capacity()) reallocate(); }

template <typename T>
std::pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e) {
	T *data = alloc.allocate(e - b);
	return {data, std::uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free() {
	if (elements) {
		for (T *p = first_free; p != elements; )
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

template <typename T>
void Vec<T>::reallocate() {
	std::size_t new_capacity = size() ? 2 * size() : 1;
	T *data = alloc.allocate(new_capacity);	
	T *dest = data;
	T *elem = elements;
	for (std::size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = data;
	first_free = dest;
	cap = elements + new_capacity;
}

#endif
