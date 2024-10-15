#ifndef CHAPTER16_H
#define CHAPTER16_H

#include <functional>
#include <string>
#include <iostream>
#include <cstddef>
#include <vector>
#include <initializer_list>
#include <memory>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <cctype>
#include <iterator>
#include <cstring>

namespace cplusplus_primer {
	namespace chapter16 {
	namespace _02 {
		template <typename T> int compare(const T &v1, const T &v2) {
			if (std::less<T>()(v1, v2)) return -1;
			if (std::less<T>()(v2, v1)) return 1;
			return 0;
		}
	}
	namespace _03 {
		template <typename T>
		int compare(const T &v1, const T &v2) {
			if (std::less<T>()(v1, v2)) return -1;
			if (std::less<T>()(v2, v1)) return 1;
			return 0;
		}
		class Sales_data;
			std::istream &read(std::istream&, Sales_data&);

		class Sales_data {
			friend std::istream &read(std::istream&, Sales_data&);
			friend std::ostream &print(std::ostream&, const Sales_data&);
			friend Sales_data add(const Sales_data&, const Sales_data&);
			
			friend std::ostream &operator<<(std::ostream &, const Sales_data &);
			friend std::istream &operator>>(std::istream &, Sales_data &);

			friend Sales_data operator+(const Sales_data &, const Sales_data &);
			friend Sales_data operator-(const Sales_data &, const Sales_data &);
			friend Sales_data operator*(const Sales_data &, const Sales_data &);
			friend Sales_data operator/(const Sales_data &, const Sales_data &);

		public:
			Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {
				//std::cout << "mainConstructor" << std::endl;
			}
			Sales_data() : Sales_data("", 0, 0) {
				//std::cout << "empty" << std::endl;	
			}
			Sales_data(const std::string &s) : Sales_data(s, 0, 0) {
				//std::cout << "string" << std::endl;
			}
			Sales_data(std::istream &is) : Sales_data() {
				read(is, *this);
				//std::cout << "istream" << std::endl;
			}

			Sales_data &combine(const Sales_data&);
			std::string isbn() const { return bookNo; }
			
			Sales_data &operator+=(const Sales_data &);		// compound-assignment
			Sales_data &operator=(const std::string &);		// copy-assignment operator
			
			explicit operator std::string() const { return bookNo; }
			explicit operator double() const { return revenue; }
		private:
			double avg_price() const;
			std::string bookNo;
			unsigned units_sold = 0;
			double revenue = 0.0;
		};

		std::istream &operator>>(std::istream &, Sales_data &);			// input operator
		std::ostream &operator<<(std::ostream &, const Sales_data &);	// output operator
		Sales_data operator+(const Sales_data &, const Sales_data &);	// addition operator
		Sales_data operator-(const Sales_data &, const Sales_data &);	// subtraction operator
		Sales_data operator*(const Sales_data &, const Sales_data &);	// multiplication operator
		Sales_data operator/(const Sales_data &, const Sales_data &);	// division operator

		Sales_data add(const Sales_data&, const Sales_data&);
		std::ostream &print(std::ostream&, const Sales_data&);

		// inline and constexpr functions should be defined in the class headers
		inline
		double Sales_data::avg_price() const {
			return units_sold ? revenue / units_sold : 0;
		}
	}
	namespace _04 {
		template <typename It, typename T>
		It find_val(It beg, It end, const T &val) {
			while (beg != end && *beg != val) {
				++beg;
			}
			return beg;
		}
	}
	namespace _05 {
		template <typename T, std::size_t N>
		void print(const T (&arr)[N]) {
			for (const T &elem : arr)
				std::cout << elem << std::endl;
		}
	}
	namespace _06 {
		template <typename T, std::size_t N>
		T *arr_begin(T (&arr)[N]) {
			return arr;
		}

		template <typename T, std::size_t N>
		T *arr_end(T (&arr)[N]) {
			return arr + N;
		}
	}
	namespace _07 {
		template <typename T, std::size_t N>
		constexpr std::size_t arr_size(const T (&)[N]) {
			return N;
		}
	}
	namespace _12 {
		template <typename T> class Blob;
		template <typename T> class BlobPtr;
		template <typename T> class ConstBlobPtr;

		template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);

		template <typename T>
		class Blob {
			friend class BlobPtr<T>;
			friend class ConstBlobPtr<T>;
			friend bool operator==<T>(const Blob<T> &, const Blob<T> &);
		public:
			typedef T value_type;
			typedef typename std::vector<T>::size_type size_type;

			Blob();
			Blob(std::initializer_list<T>);

			BlobPtr<T> begin();
			BlobPtr<T> end();
			ConstBlobPtr<T> cbegin() const;
			ConstBlobPtr<T> cend() const;

			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }

			void push_back(const T &elem) {	data->push_back(elem); }
			void push_back(T &&elem) { data->push_back(std::move(elem)); }
			void pop_back();
			
			T &front();
			const T &front() const;
			T &back();
			const T &back() const;
			T &operator[](size_type);
			const T &operator[](size_type) const;

		private:
			void check(size_type, const std::string &) const;
			std::shared_ptr<std::vector<T>> data;
		};

		template <typename T>
		Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

		template <typename T>
		Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}

		template <typename T>
		void Blob<T>::check(size_type i, const std::string &msg) const {
			if (i >= data->size())
				throw std::out_of_range(msg);
		}

		template <typename T>
		T &Blob<T>::front() {
			check(0, "front on empty Blob");
			return data->front();
		}
		template <typename T>
		const T &Blob<T>::front() const {
			check(0, "front on empty Blob");
			return data->front();
		}
		template <typename T>
		T &Blob<T>::back() {
			check(0, "back on empty Blob");
			return data->back();
		}
		template <typename T>
		const T &Blob<T>::back() const {
			check(0, "back on empty Blob");
			return data->back();
		}
		template <typename T>
		T &Blob<T>::operator[](size_type i) {
			check(i, "subscript out of range");
			return (*data)[i];
		}
		template <typename T>
		const T &Blob<T>::operator[](size_type i) const {
			check(i, "subscript out of range");
			return (*data)[i];
		}
		template <typename T>
		void Blob<T>::pop_back() {
			check(0, "pop back on empty Blob");
			data->pop_back();
		}

		// Equality operators for Blob
		template <typename T>
		bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
			return *lhs.data == *rhs.data;
		}
		template <typename T>
		bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs) {
			return !(lhs == rhs);
		}

		// Blob member functions dependent on the BlobPtr types

		template <typename T>
		BlobPtr<T> Blob<T>::begin() {
			return BlobPtr<T>(*this, 0);
		}
		template <typename T>
		BlobPtr<T> Blob<T>::end() {
			return BlobPtr<T>(*this, size());
		}
		template <typename T>
		ConstBlobPtr<T> Blob<T>::cbegin() const {
			return ConstBlobPtr<T>(*this, 0);
		}
		template <typename T>
		ConstBlobPtr<T> Blob<T>::cend() const {
			return ConstBlobPtr<T>(*this, size());
		}

		template <typename T> class Blob;
		template <typename T> class BlobPtr;

		template <typename T> bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
		template <typename T> bool operator<(const BlobPtr<T> &, const BlobPtr<T> &);
		template <typename T> std::ptrdiff_t operator-(const BlobPtr<T> &, const BlobPtr<T> &);

		template <typename T>
		class BlobPtr {
			friend bool operator==<T>(const BlobPtr<T> &, const BlobPtr<T> &);
			friend bool operator< <T>(const BlobPtr<T> &, const BlobPtr<T> &);
			friend std::ptrdiff_t operator-<T>(const BlobPtr<T> &, const BlobPtr<T> &);
		public:
			BlobPtr();
			BlobPtr(Blob<T> &, std::size_t = 0);

			T &operator*() const;

			BlobPtr &operator+=(std::size_t);
			BlobPtr &operator-=(std::size_t);

			BlobPtr &operator++();		// prefix
			BlobPtr &operator--();
			BlobPtr operator++(int);	// postfix
			BlobPtr operator--(int);

		private:
			std::shared_ptr<std::vector<T>>	check(std::size_t, const std::string &) const;

			std::weak_ptr<std::vector<T>> wptr;
			std::size_t curr;
		};

		template <typename T>
		BlobPtr<T>::BlobPtr() : curr(0) {}

		template <typename T>
		BlobPtr<T>::BlobPtr(Blob<T> &a, std::size_t sz) : wptr(a.data), curr(sz)  {}
		// Dereference
		template <typename T>
		T &BlobPtr<T>::operator*() const {
			std::shared_ptr<std::vector<T>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}
		// Compound addition assignment
		template <typename T>
		BlobPtr<T> &BlobPtr<T>::operator+=(std::size_t n) {
			curr += n;
			check(curr - 1, "increment past end of BlobPtr");
			return *this;
		}
		// Compound subtraction assignment
		template <typename T>
		BlobPtr<T> &BlobPtr<T>::operator-=(std::size_t n) {
			curr -= n;
			check(curr, "decrement past beginning of BlobPtr");
			return *this;
		}
		// Prefix increment
		template <typename T>
		BlobPtr<T> &BlobPtr<T>::operator++() {
			check(curr, "increment past end of BlobPtr");
			++curr;
			return *this;
		}
		// Prefix decrement
		template <typename T>
		BlobPtr<T> &BlobPtr<T>::operator--() {
			check(--curr, "decrement past beginning of BlobPtr");
			return *this;
		}
		// Postfix increment
		template <typename T>
		BlobPtr<T> BlobPtr<T>::operator++(int) {
			BlobPtr old = *this;
			++*this;
			return old;
		}
		// Postfix decrement
		template <typename T>
		BlobPtr<T> BlobPtr<T>::operator--(int) {
			BlobPtr old = *this;
			--*this;
			return old;
		}

		template <typename T>
		std::shared_ptr<std::vector<T>> 
		BlobPtr<T>::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<T>> ret = wptr.lock();
			if (!ret)
				throw std::runtime_error("unbound BlobPtr");
			if (i >= ret->size())
				throw std::out_of_range(msg);
			return ret;
		}

		// Equality
		template <typename T>
		bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
			return (lhs.wptr.lock() == rhs.wptr.lock())
					&& (lhs.curr == rhs.curr);
		}
		// Inequality
		template <typename T>
		bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
			return !(lhs == rhs);
		}
		// Less-than
		template <typename T>
		bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("comparing two BlobPtrs that don't point to the same object");
			return lhs.curr < rhs.curr;
		}
		// Greater-than
		template <typename T>
		bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
			return rhs < lhs;
		}
		// Less-than or equal
		template <typename T>
		bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
			return !(lhs > rhs);
		}
		// Greater-than or equal
		template <typename T>
		bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
			return !(lhs < rhs);
		}
		// Addition
		template <typename T>
		BlobPtr<T> operator+(const BlobPtr<T> &p, std::size_t n) {
			BlobPtr<T> ret = p;
			ret += n;
			return ret;
		}
		// Subtraction
		template <typename T>
		BlobPtr<T> operator-(const BlobPtr<T> &p, std::size_t n) {
			BlobPtr<T> ret = p;
			ret -= n;
			return ret;
		}
		// Subtraction
		template <typename T>
		std::ptrdiff_t operator-(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("the two BlobPtrs don't point to the same object");
			return lhs.curr - rhs.curr;
		}

		template <typename T> class Blob;
		template <typename T> class ConstBlobPtr;

		template <typename T> bool operator==(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
		template <typename T> bool operator<(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
		template <typename T> std::ptrdiff_t operator-(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);

		template <typename T>
		class ConstBlobPtr {
			friend bool operator==<T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
			friend bool operator< <T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
			friend std::ptrdiff_t operator-<T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
		public:
			ConstBlobPtr();
			ConstBlobPtr(const Blob<T> &, std::size_t = 0);

			const T &operator*() const;

			ConstBlobPtr &operator+=(std::size_t);
			ConstBlobPtr &operator-=(std::size_t);

			ConstBlobPtr &operator++();		// prefix
			ConstBlobPtr &operator--();
			ConstBlobPtr operator++(int);	// postfix
			ConstBlobPtr operator--(int);

		private:
			std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
			
			std::weak_ptr<std::vector<T>> wptr;
			std::size_t curr;
		};

		template <typename T>
		ConstBlobPtr<T>::ConstBlobPtr() : curr(0) {}

		template <typename T>
		ConstBlobPtr<T>::ConstBlobPtr(const Blob<T> &a, std::size_t sz) : wptr(a.data), curr(sz) {}
		// Dereference
		template <typename T>
		const T &ConstBlobPtr<T>::operator*() const {
			std::shared_ptr<std::vector<T>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}
		// Compound addition assignment
		template <typename T>
		ConstBlobPtr<T> &ConstBlobPtr<T>::operator+=(std::size_t n) {
			curr += n;
			check(curr - 1, "increment past end of ConstBlobPtr");
			return *this;
		}
		// Compound subtraction assignment
		template <typename T>
		ConstBlobPtr<T> &ConstBlobPtr<T>::operator-=(std::size_t n) {
			curr -= n;
			check(curr, "decrement past beginning of ConstBlobPtr");
			return *this;
		}
		// Prefix increment
		template <typename T>
		ConstBlobPtr<T> &ConstBlobPtr<T>::operator++() {
			check(curr, "increment past end of ConstBlobPtr");
			++curr;
			return *this;
		}
		// Prefix decrement
		template <typename T>
		ConstBlobPtr<T> &ConstBlobPtr<T>::operator--() {
			check(--curr, "decrement past beginning of ConstBlobPtr");
			return *this;
		}
		// Postfix increment
		template <typename T>
		ConstBlobPtr<T> ConstBlobPtr<T>::operator++(int) {
			ConstBlobPtr old = *this;
			++*this;
			return old;
		}
		// Postfix decrement
		template <typename T>
		ConstBlobPtr<T> ConstBlobPtr<T>::operator--(int) {
			ConstBlobPtr old = *this;
			--*this;
			return old;
		}

		template <typename T>
		std::shared_ptr<std::vector<T>>
		ConstBlobPtr<T>::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<T>> ret = wptr.lock();
			if (!ret)
				throw std::runtime_error("unbound ConstBlobPtr");
			if (i >= ret->size())
				throw std::out_of_range(msg);
			return ret;
		}

		// Equality
		template <typename T>
		bool operator==(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
			return (lhs.wptr.lock() == rhs.wptr.lock())
					&& (lhs.curr == rhs.curr);
		}
		// Inequality
		template <typename T>
		bool operator!=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
			return !(lhs == rhs);
		}
		// Less-than
		template <typename T>
		bool operator<(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("comparing two ConstBlobPtrs that don't point to the same object");
			return lhs.curr < rhs.curr;
		}
		// Greater-than
		template <typename T>
		bool operator>(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
			return rhs < lhs;
		}
		// Less-than or equal
		template <typename T>
		bool operator<=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
			return !(lhs > rhs);
		}
		// Greater-than or equal
		template <typename T>
		bool operator>=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
			return !(lhs < rhs);
		}
		// Addition
		template <typename T>
		ConstBlobPtr<T> operator+(const ConstBlobPtr<T> &p, const std::size_t n) {
			ConstBlobPtr<T> ret = p;
			ret += n;
			return ret;
		}
		// Subtraction
		template <typename T>
		ConstBlobPtr<T> operator-(const ConstBlobPtr<T> &p, const std::size_t n) {
			ConstBlobPtr<T> ret = p;
			ret -= n;
			return ret;
		}
		// Subtraction
		template <typename T>
		std::ptrdiff_t operator-(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("the two ConstBlobPtrs don't point to the same object");
			return lhs.curr - rhs.curr;
		}
	}
	namespace _14 {
		template <std::string::size_type height, std::string::size_type width>
		class Screen {
		public:
			typedef std::string::size_type pos;
			Screen() : contents(height * width, ' ') {}
			Screen(char c) : contents(height * width, c) {}

			char get() const { return contents[cursor]; }
			char get(pos, pos) const;
			Screen &move(pos, pos);
			
			Screen &set(char);
			Screen &set(pos, pos, char);
			Screen &display(std::ostream &os) { do_display(os); return *this; }
			const Screen &display(std::ostream &os) const { do_display(os); return *this; }
		private:
			void do_display(std::ostream &os) const { os << contents; }

			pos cursor = 0;
			std::string contents;
		};

		template <std::string::size_type height, std::string::size_type width>
		inline char Screen<height, width>::get(pos r, pos c) const {
			return contents[r * width + c];
		}

		template <std::string::size_type height, std::string::size_type width>
		inline Screen<height, width> &Screen<height, width>::move(pos r, pos c) {
			cursor = r * width + c;
			return *this;
		}

		template <std::string::size_type height, std::string::size_type width>
		inline Screen<height, width> &Screen<height, width>::set(char c) {
			contents[cursor] = c;
			return *this;
		}

		template <std::string::size_type height, std::string::size_type width>
		inline Screen<height, width> &Screen<height, width>::set(pos r, pos c, char ch) {
			contents[r * width + c] = ch;
			return *this;
		}
	}
	namespace _15 {
		template <std::string::size_type height, std::string::size_type width>
		class Screen {
		public:
			typedef std::string::size_type pos;
			Screen() : contents(height * width, ' ') {}
			Screen(char c) : contents(height * width, c) {}

			char get() const { return contents[cursor]; }
			char get(pos, pos) const;
			Screen &move(pos, pos);
			
			Screen &set(char);
			Screen &set(pos, pos, char);
			Screen &display(std::ostream &os) { do_display(os); return *this; }
			const Screen &display(std::ostream &os) const { do_display(os); return *this; }
		private:
			void do_display(std::ostream &os) const { os << contents; }

			pos cursor = 0;
			std::string contents;
		};

		template <std::string::size_type height, std::string::size_type width>
		inline char Screen<height, width>::get(pos r, pos c) const {
			return contents[r * width + c];
		}

		template <std::string::size_type height, std::string::size_type width>
		inline Screen<height, width> &Screen<height, width>::move(pos r, pos c) {
			cursor = r * width + c;
			return *this;
		}

		template <std::string::size_type height, std::string::size_type width>
		inline Screen<height, width> &Screen<height, width>::set(char c) {
			contents[cursor] = c;
			return *this;
		}

		template <std::string::size_type height, std::string::size_type width>
		inline Screen<height, width> &Screen<height, width>::set(pos r, pos c, char ch) {
			contents[r * width + c] = ch;
			return *this;
		}

		template <std::string::size_type height, std::string::size_type width>
		std::ostream &operator<<(std::ostream &os, const Screen<height, width> &s) {
			s.display(os);
			return os;
		}

		template <std::string::size_type height, std::string::size_type width>
		std::istream &operator>>(std::istream &is, Screen<height, width> &s) {
			char ch;
			for (std::string::size_type y = 0; y != height; ++y)
				for (std::string::size_type x = 0; x != width; ++x) {
					is >> ch;
					s.set(y, x, ch);
				}
				
			return is;
		}
	}
	namespace _16 {
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
	}
	namespace _21 {
		class DebugDelete {
		public:
			DebugDelete(std::ostream &s = std::cerr) : os(s) {}
			template <typename T>
			void operator()(T *p) const {
				os << "deleting unique_ptr" << std::endl;
				delete p;
			}
		private:
			std::ostream &os;
		};
	}
	namespace _22 {
		class DebugDelete {
		public:
			DebugDelete(std::ostream &s = std::cerr) : os(s) {}
			template <typename T>
			void operator()(T *p) const {
				os << "deleting unique_ptr" << std::endl;
				delete p;
			}
		private:
			std::ostream &os;
		};

		class StrBlobPtr;
		class ConstStrBlobPtr;

		class StrBlob {
			friend class StrBlobPtr;
			friend class ConstStrBlobPtr;
		public:
			typedef std::vector<std::string>::size_type size_type;
			
			StrBlob();
			StrBlob(std::initializer_list<std::string>);

			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }
			
			void push_back(const std::string &s) { data->push_back(s); }
			void pop_back();
			
			std::string &front();
			std::string &back();

			StrBlobPtr begin();
			StrBlobPtr end();

			ConstStrBlobPtr cbegin() const;
			ConstStrBlobPtr cend() const;
		private:
			std::shared_ptr<std::vector<std::string>> data;
			void check(size_type, const std::string &) const;
		};

		class StrBlobPtr {
		public:
			StrBlobPtr() : curr(0) {}
			StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
			std::string &deref() const;
			StrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		class ConstStrBlobPtr {
		public:
			ConstStrBlobPtr() : curr(0) {}
			ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
			const std::string &deref() const;
			ConstStrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		class QueryResult;

		class TextQuery {
		public:
			typedef StrBlob::size_type line_no;
			TextQuery(std::ifstream &in) : file(new StrBlob(), DebugDelete()) {
				line_no line_num = 0;
				for (std::string line; std::getline(in, line); file->push_back(line), ++line_num) {
					std::string word;
					std::istringstream stream(line);
					while (stream >> word) {
						
						// erase not alphanumeric characters from the current word
						word.erase(std::remove_if(word.begin(), word.end(), [](char c){ return !std::isalnum(c); }), word.end());
						
						// transform current word's all characters to lowercase
						std::transform(word.begin(), word.end(), word.begin(), [](char c){ return std::tolower(c); });
						
						std::shared_ptr<std::set<line_no>> &lines = wm[word];
						if (!lines)
							lines.reset(new std::set<line_no>, DebugDelete());
						lines->insert(line_num);
					}
				}
			}
			QueryResult query(const std::string &) const;
		private:
			std::shared_ptr<StrBlob> file;
			std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
		};

		class QueryResult {
		friend std::ostream &print(std::ostream &, const QueryResult &);
		public:
			typedef StrBlob::size_type line_no;
			QueryResult(const std::string &s, std::shared_ptr<std::set<line_no>> l, std::shared_ptr<StrBlob> f)
					: sought(s), line_nums(l), file(f) {}
			
			std::set<line_no>::iterator begin() { return line_nums->begin(); }
			std::set<line_no>::iterator end() { return line_nums->end(); }
			std::shared_ptr<StrBlob> get_file() const { return file; }
		private:
			std::string sought;
			std::shared_ptr<std::set<line_no>> line_nums;
			std::shared_ptr<StrBlob> file;
		};

		class Query_base {
			friend class Query;
		protected:
			using line_no = TextQuery::line_no;
			virtual ~Query_base() = default;
		private:
			virtual std::string rep() const = 0;
			virtual QueryResult eval(const TextQuery &) const = 0;
		};

		class WordQuery : public Query_base {
			friend class Query;

			WordQuery(const std::string &s) : query_word(s) {}
			
			std::string rep() const override {
				return query_word;
			}
			QueryResult eval(const TextQuery &t) const override {
				return t.query(query_word);
			}

			std::string query_word;
		};

		class Query {
			friend Query operator~(const Query &);
			friend Query operator|(const Query &, const Query &);
			friend Query operator&(const Query &, const Query &);
		public:
			Query(const std::string &s) : q(new WordQuery(s), DebugDelete()) {}

			std::string rep() const {
				return q->rep();
			}
			QueryResult eval(const TextQuery &t) const {
				return q->eval(t);
			}
		private:
			Query(std::shared_ptr<Query_base> query) : q(query) {}

			std::shared_ptr<Query_base> q;
		};

		std::ostream &operator<<(std::ostream &, const Query &);

		class NotQuery : public Query_base {
			friend Query operator~(const Query &);
			NotQuery(const Query &q) : query(q) {
				std::cout << "NotQuery::NotQuery" << std::endl;
			}

			std::string rep() const override {
				std::cout << "NotQuery::rep" << std::endl;
				return "~(" + query.rep() + ")";
			}
			QueryResult eval(const TextQuery &) const override;

			Query query;
		};

		inline Query operator~(const Query &operand) {
			return std::shared_ptr<Query_base>(new NotQuery(operand), DebugDelete());
		}

		class BinaryQuery : public Query_base {
		protected:
			BinaryQuery(const Query &l, const Query &r, std::string s)
				: lhs(l), rhs(r), opSym(s) {}
			std::string rep() const {
					return "(" + lhs.rep() + " "
							   + opSym + " "
							   + rhs.rep() + ")";
			}
			Query lhs, rhs;
			std::string opSym;
		};

		class AndQuery : public BinaryQuery {
			friend Query operator&(const Query &, const Query &);
			AndQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "&") {}
			QueryResult eval(const TextQuery &) const override;
		};

		inline Query operator&(const Query &lhs, const Query &rhs) {
			return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs), DebugDelete());
		}

		class OrQuery : public BinaryQuery {
			friend Query operator|(const Query &, const Query &);
			OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {}
			QueryResult eval(const TextQuery &) const override;
		};

		inline Query operator|(const Query &lhs, const Query &rhs) {
			return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs), DebugDelete());
		}
	}
	namespace _24 {
		template <typename T> class Blob;
		template <typename T> class BlobPtr;
		template <typename T> class ConstBlobPtr;

		template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);

		template <typename T>
		class Blob {
			friend class BlobPtr<T>;
			friend class ConstBlobPtr<T>;
			friend bool operator==<T>(const Blob<T> &, const Blob<T> &);
		public:
			typedef T value_type;
			typedef typename std::vector<T>::size_type size_type;

			Blob();
			Blob(std::initializer_list<T>);
			template <typename It>
			Blob(It, It);

			BlobPtr<T> begin();
			BlobPtr<T> end();
			ConstBlobPtr<T> cbegin() const;
			ConstBlobPtr<T> cend() const;

			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }

			void push_back(const T &elem) {	data->push_back(elem); }
			void push_back(T &&elem) { data->push_back(std::move(elem)); }
			void pop_back();
			
			T &front();
			const T &front() const;
			T &back();
			const T &back() const;
			T &operator[](size_type);
			const T &operator[](size_type) const;

		private:
			void check(size_type, const std::string &) const;
			std::shared_ptr<std::vector<T>> data;
		};

		template <typename T>
		Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

		template <typename T>
		Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}

		template <typename T>
		template <typename It>
			Blob<T>::Blob(It b, It e) : data(std::make_shared<std::vector<T>>(b, e)) {}

		template <typename T>
		void Blob<T>::check(size_type i, const std::string &msg) const {
			if (i >= data->size())
				throw std::out_of_range(msg);
		}

		template <typename T>
		T &Blob<T>::front() {
			check(0, "front on empty Blob");
			return data->front();
		}
		template <typename T>
		const T &Blob<T>::front() const {
			check(0, "front on empty Blob");
			return data->front();
		}
		template <typename T>
		T &Blob<T>::back() {
			check(0, "back on empty Blob");
			return data->back();
		}
		template <typename T>
		const T &Blob<T>::back() const {
			check(0, "back on empty Blob");
			return data->back();
		}
		template <typename T>
		T &Blob<T>::operator[](size_type i) {
			check(i, "subscript out of range");
			return (*data)[i];
		}
		template <typename T>
		const T &Blob<T>::operator[](size_type i) const {
			check(i, "subscript out of range");
			return (*data)[i];
		}
		template <typename T>
		void Blob<T>::pop_back() {
			check(0, "pop back on empty Blob");
			data->pop_back();
		}

		// Equality operators for Blob
		template <typename T>
		bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
			return *lhs.data == *rhs.data;
		}
		template <typename T>
		bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs) {
			return !(lhs == rhs);
		}

		// Blob member functions dependent on the BlobPtr types
		template <typename T>
		BlobPtr<T> Blob<T>::begin() {
			return BlobPtr<T>(*this, 0);
		}
		template <typename T>
		BlobPtr<T> Blob<T>::end() {
			return BlobPtr<T>(*this, size());
		}
		template <typename T>
		ConstBlobPtr<T> Blob<T>::cbegin() const {
			return ConstBlobPtr<T>(*this, 0);
		}
		template <typename T>
		ConstBlobPtr<T> Blob<T>::cend() const {
			return ConstBlobPtr<T>(*this, size());
		}

		template <typename T> class Blob;
		template <typename T> class BlobPtr;

		template <typename T> bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
		template <typename T> bool operator<(const BlobPtr<T> &, const BlobPtr<T> &);
		template <typename T> std::ptrdiff_t operator-(const BlobPtr<T> &, const BlobPtr<T> &);

		template <typename T>
		class BlobPtr {
			friend bool operator==<T>(const BlobPtr<T> &, const BlobPtr<T> &);
			friend bool operator< <T>(const BlobPtr<T> &, const BlobPtr<T> &);
			friend std::ptrdiff_t operator-<T>(const BlobPtr<T> &, const BlobPtr<T> &);
		public:
			BlobPtr();
			BlobPtr(Blob<T> &, std::size_t = 0);

			T &operator*() const;

			BlobPtr &operator+=(std::size_t);
			BlobPtr &operator-=(std::size_t);

			BlobPtr &operator++();		// prefix
			BlobPtr &operator--();
			BlobPtr operator++(int);	// postfix
			BlobPtr operator--(int);

		private:
			std::shared_ptr<std::vector<T>>	check(std::size_t, const std::string &) const;

			std::weak_ptr<std::vector<T>> wptr;
			std::size_t curr;
		};

		template <typename T>
		BlobPtr<T>::BlobPtr() : curr(0) {}

		template <typename T>
		BlobPtr<T>::BlobPtr(Blob<T> &a, std::size_t sz) : wptr(a.data), curr(sz)  {}
		// Dereference
		template <typename T>
		T &BlobPtr<T>::operator*() const {
			std::shared_ptr<std::vector<T>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}
		// Compound addition assignment
		template <typename T>
		BlobPtr<T> &BlobPtr<T>::operator+=(std::size_t n) {
			curr += n;
			check(curr - 1, "increment past end of BlobPtr");
			return *this;
		}
		// Compound subtraction assignment
		template <typename T>
		BlobPtr<T> &BlobPtr<T>::operator-=(std::size_t n) {
			curr -= n;
			check(curr, "decrement past beginning of BlobPtr");
			return *this;
		}
		// Prefix increment
		template <typename T>
		BlobPtr<T> &BlobPtr<T>::operator++() {
			check(curr, "increment past end of BlobPtr");
			++curr;
			return *this;
		}
		// Prefix decrement
		template <typename T>
		BlobPtr<T> &BlobPtr<T>::operator--() {
			check(--curr, "decrement past beginning of BlobPtr");
			return *this;
		}
		// Postfix increment
		template <typename T>
		BlobPtr<T> BlobPtr<T>::operator++(int) {
			BlobPtr old = *this;
			++*this;
			return old;
		}
		// Postfix decrement
		template <typename T>
		BlobPtr<T> BlobPtr<T>::operator--(int) {
			BlobPtr old = *this;
			--*this;
			return old;
		}

		template <typename T>
		std::shared_ptr<std::vector<T>> 
		BlobPtr<T>::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<T>> ret = wptr.lock();
			if (!ret)
				throw std::runtime_error("unbound BlobPtr");
			if (i >= ret->size())
				throw std::out_of_range(msg);
			return ret;
		}

		// Equality
		template <typename T>
		bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
			return (lhs.wptr.lock() == rhs.wptr.lock())
					&& (lhs.curr == rhs.curr);
		}
		// Inequality
		template <typename T>
		bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
			return !(lhs == rhs);
		}
		// Less-than
		template <typename T>
		bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("comparing two BlobPtrs that don't point to the same object");
			return lhs.curr < rhs.curr;
		}
		// Greater-than
		template <typename T>
		bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
			return rhs < lhs;
		}
		// Less-than or equal
		template <typename T>
		bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
			return !(lhs > rhs);
		}
		// Greater-than or equal
		template <typename T>
		bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
			return !(lhs < rhs);
		}
		// Addition
		template <typename T>
		BlobPtr<T> operator+(const BlobPtr<T> &p, std::size_t n) {
			BlobPtr<T> ret = p;
			ret += n;
			return ret;
		}
		// Subtraction
		template <typename T>
		BlobPtr<T> operator-(const BlobPtr<T> &p, std::size_t n) {
			BlobPtr<T> ret = p;
			ret -= n;
			return ret;
		}
		// Subtraction
		template <typename T>
		std::ptrdiff_t operator-(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("the two BlobPtrs don't point to the same object");
			return lhs.curr - rhs.curr;
		}

		template <typename T> class Blob;
		template <typename T> class ConstBlobPtr;

		template <typename T> bool operator==(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
		template <typename T> bool operator<(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
		template <typename T> std::ptrdiff_t operator-(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);

		template <typename T>
		class ConstBlobPtr {
			friend bool operator==<T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
			friend bool operator< <T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
			friend std::ptrdiff_t operator-<T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
		public:
			ConstBlobPtr();
			ConstBlobPtr(const Blob<T> &, std::size_t = 0);

			const T &operator*() const;

			ConstBlobPtr &operator+=(std::size_t);
			ConstBlobPtr &operator-=(std::size_t);

			ConstBlobPtr &operator++();		// prefix
			ConstBlobPtr &operator--();
			ConstBlobPtr operator++(int);	// postfix
			ConstBlobPtr operator--(int);

		private:
			std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
			
			std::weak_ptr<std::vector<T>> wptr;
			std::size_t curr;
		};

		template <typename T>
		ConstBlobPtr<T>::ConstBlobPtr() : curr(0) {}

		template <typename T>
		ConstBlobPtr<T>::ConstBlobPtr(const Blob<T> &a, std::size_t sz) : wptr(a.data), curr(sz) {}
		// Dereference
		template <typename T>
		const T &ConstBlobPtr<T>::operator*() const {
			std::shared_ptr<std::vector<T>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}
		// Compound addition assignment
		template <typename T>
		ConstBlobPtr<T> &ConstBlobPtr<T>::operator+=(std::size_t n) {
			curr += n;
			check(curr - 1, "increment past end of ConstBlobPtr");
			return *this;
		}
		// Compound subtraction assignment
		template <typename T>
		ConstBlobPtr<T> &ConstBlobPtr<T>::operator-=(std::size_t n) {
			curr -= n;
			check(curr, "decrement past beginning of ConstBlobPtr");
			return *this;
		}
		// Prefix increment
		template <typename T>
		ConstBlobPtr<T> &ConstBlobPtr<T>::operator++() {
			check(curr, "increment past end of ConstBlobPtr");
			++curr;
			return *this;
		}
		// Prefix decrement
		template <typename T>
		ConstBlobPtr<T> &ConstBlobPtr<T>::operator--() {
			check(--curr, "decrement past beginning of ConstBlobPtr");
			return *this;
		}
		// Postfix increment
		template <typename T>
		ConstBlobPtr<T> ConstBlobPtr<T>::operator++(int) {
			ConstBlobPtr old = *this;
			++*this;
			return old;
		}
		// Postfix decrement
		template <typename T>
		ConstBlobPtr<T> ConstBlobPtr<T>::operator--(int) {
			ConstBlobPtr old = *this;
			--*this;
			return old;
		}

		template <typename T>
		std::shared_ptr<std::vector<T>>
		ConstBlobPtr<T>::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<T>> ret = wptr.lock();
			if (!ret)
				throw std::runtime_error("unbound ConstBlobPtr");
			if (i >= ret->size())
				throw std::out_of_range(msg);
			return ret;
		}

		// Equality
		template <typename T>
		bool operator==(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
			return (lhs.wptr.lock() == rhs.wptr.lock())
					&& (lhs.curr == rhs.curr);
		}
		// Inequality
		template <typename T>
		bool operator!=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
			return !(lhs == rhs);
		}
		// Less-than
		template <typename T>
		bool operator<(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("comparing two ConstBlobPtrs that don't point to the same object");
			return lhs.curr < rhs.curr;
		}
		// Greater-than
		template <typename T>
		bool operator>(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
			return rhs < lhs;
		}
		// Less-than or equal
		template <typename T>
		bool operator<=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
			return !(lhs > rhs);
		}
		// Greater-than or equal
		template <typename T>
		bool operator>=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
			return !(lhs < rhs);
		}
		// Addition
		template <typename T>
		ConstBlobPtr<T> operator+(const ConstBlobPtr<T> &p, const std::size_t n) {
			ConstBlobPtr<T> ret = p;
			ret += n;
			return ret;
		}
		// Subtraction
		template <typename T>
		ConstBlobPtr<T> operator-(const ConstBlobPtr<T> &p, const std::size_t n) {
			ConstBlobPtr<T> ret = p;
			ret -= n;
			return ret;
		}
		// Subtraction
		template <typename T>
		std::ptrdiff_t operator-(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("the two ConstBlobPtrs don't point to the same object");
			return lhs.curr - rhs.curr;
		}
	}
	namespace _28 {
		class DebugDelete {
		public:
			DebugDelete(std::ostream &s = std::cerr) : os(s) {}
			DebugDelete(const DebugDelete &d) : os(d.os) {}
			DebugDelete(DebugDelete &&d) noexcept : os(d.os) {}
			DebugDelete &operator=(const DebugDelete &rhs) {
				return *this;
			}
			DebugDelete &operator=(DebugDelete &&rhs) noexcept {
				return *this;
			}
			template <typename T>
			void operator()(T *p) const {
				os << "deleting unique_ptr" << std::endl;
				delete p;
			}
		private:
			std::ostream &os;
		};

		template <typename T> class SharedPtr;
		template <typename T> void swap(SharedPtr<T> &, SharedPtr<T> &);

		template <typename T>
		class SharedPtr {
			friend void swap<T>(SharedPtr<T> &, SharedPtr<T> &);
		public:
			using element_type = T;

			SharedPtr() : element(nullptr), use(new std::size_t(0)) {}
			SharedPtr(T *p) : element(p), use(new std::size_t(p ? 1 : 0)) {}
			template <typename Deleter>
			SharedPtr(T *p, Deleter d) : element(p), use(new std::size_t(p ? 1 : 0)), del(d) {}
			
			SharedPtr(const SharedPtr &p) : element(p.element), use(p.use), del(p.del) {
				if (p)
					++*use;
			}
			template <typename Deleter>
			SharedPtr(const SharedPtr &p, Deleter d) : element(p.element), use(p.use), del(d) {
				if (p)
					++*use;
			}

			SharedPtr(SharedPtr &&p) noexcept : element(p.element), use(p.use), del(std::move(p.del)) {
				p.element = nullptr;
				p.use = nullptr;
			}

			SharedPtr &operator=(const SharedPtr &rhs) {
				if (this != &rhs) {
					deletion_logic();
					element = rhs.element;
					use = rhs.use;
					del = rhs.del;
					if (element)
						++*use;
				}
				return *this;
			}
			SharedPtr &operator=(SharedPtr &&rhs) noexcept {
				if (this != &rhs) {
					deletion_logic();
					element = rhs.element;
					use = rhs.use;
					del = std::move(rhs.del);
					rhs.element = nullptr;
					rhs.use = nullptr;
				}
				return *this;
			}
			~SharedPtr() {
				deletion_logic();
			}

			std::size_t use_count() const { return *use; }
			bool unique() const { return use_count() == 1; }

			T *get() { return element; }
			const T *get() const { return element; }

			void swap(SharedPtr &s) {
				using std::swap;
				swap(*this, s);
			}

			void reset() {
				deletion_logic();
				element = nullptr;
				use = new std::size_t(0);
				del = std::function<void (T *)>();
			}
			void reset(T *p) {
				deletion_logic();
				element = p;
				if (p)
					use = new std::size_t(1);
				else
					use = new std::size_t(0);
				del = std::function<void (T *)>();
			}
			template <typename Deleter>
			void reset(T *p, Deleter d) {
				deletion_logic();
				element = p;
				if (p)
					use = new std::size_t(1);
				else
					use = new std::size_t(0);
				del = d;
			}

			T &operator*() { return *element; }
			const T &operator*() const { return *element; }
			T *operator->() { return &this->operator*(); }
			const T *operator->() const { return &this->operator*(); }
			explicit operator bool() const { return element; }
		private:
			// Decrement reference count, and if there are no users, delete the pointed-to element
			void deletion_logic() {
				if (use) {
					if (*use == 0) {
						delete use;
					} else if (--*use == 0) {
						del ? del(element) : delete element;
						delete use;
					}
				}
			}

			T *element;
			std::size_t *use;
			std::function<void (T *)> del;
		};

		template <typename T>
		inline void swap(SharedPtr<T> &lhs, SharedPtr<T> &rhs) {
			using std::swap;
			swap(lhs.element, rhs.element);
			swap(lhs.use, rhs.use);
			swap(lhs.del, rhs.del);
		}

		template <typename T>
		inline bool operator==(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return lhs.get() == rhs.get();
		}

		template <typename T>
		inline bool operator!=(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return !(lhs == rhs);
		}

		template <typename T>
		inline bool operator<(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return std::less<const T *>()(lhs.get(), rhs.get());
		}

		template <typename T>
		inline bool operator>(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return (rhs < lhs);
		}

		template <typename T>
		inline bool operator<=(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return !(rhs < lhs);
		}

		template <typename T>
		inline bool operator>=(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return !(lhs < rhs);
		}

		template <typename T, typename... Args>
		SharedPtr<T> MakeShared(Args&&... args) {
			return SharedPtr<T>(new T(std::forward<Args>(args)...));
		}

		struct DefaultDeleter {
			template <typename T>
			inline void operator()(T *p) const {
				delete p;
			}
		};

		template <typename T, typename D> class UniquePtr;
		template <typename T, typename D> void swap(UniquePtr<T, D> &, UniquePtr<T, D> &);

		template <typename T, typename Deleter = DefaultDeleter>
		class UniquePtr {
			friend void swap<T, Deleter>(UniquePtr<T, Deleter> &, UniquePtr<T, Deleter> &);
		public:
			using element_type = T;
			using deleter_type = Deleter;

			UniquePtr() : element(nullptr), del(Deleter()) {}
			UniquePtr(Deleter d) : element(nullptr), del(d) {}
			UniquePtr(T *p) : element(p), del(Deleter()) {}
			UniquePtr(T *p, Deleter d) : element(p), del(d) {}

			UniquePtr(const UniquePtr &) = delete;
			UniquePtr(UniquePtr &&u) noexcept : element(u.element), del(std::move(u.del)) {
				u.element = nullptr;
			}
			UniquePtr &operator=(const UniquePtr &) = delete;
			UniquePtr &operator=(UniquePtr &&rhs) noexcept {
				if (this != &rhs) {
					del(element);
					element = rhs.element;
					del = std::move(rhs.del);
					rhs.element = nullptr;
				}
				return *this;
			}
			~UniquePtr() {
				if (element)
					del(element);
			}

			T *get() { return element; }
			const T *get() const { return element; }

			void swap(UniquePtr &u) {
				using std::swap;
				swap(*this, u);
			}

			T *release() {
				T *ret = element;
				element = nullptr;
				return ret;
			}
			void reset() {
				del(element);
				element = nullptr;
			}
			void reset(T *p) {
				del(element);
				element = p;
			}
			void reset(std::nullptr_t) {
				del(element);
				element = nullptr;
			}

			T &operator*() { return *element; }
			const T &operator*() const { return *element; }
			T *operator->() { return &this->operator*(); }
			const T *operator->() const { return &this->operator*(); }

			explicit operator bool() const { return element; }
		private:

			T *element;
			Deleter del;
		};

		template <typename T, typename Deleter>
		inline void swap(UniquePtr<T, Deleter> &lhs, UniquePtr<T, Deleter> &rhs) {
			using std::swap;
			swap(lhs.element, rhs.element);
			swap(lhs.del, rhs.del);
		}

		template <typename T, typename D>
		inline bool operator==(const UniquePtr<T, D> &lhs, const UniquePtr<T, D> &rhs) {
			return lhs.get() == rhs.get();
		}

		template <typename T, typename D>
		inline bool operator!=(const UniquePtr<T, D> &lhs, const UniquePtr<T, D> &rhs) {
			return !(lhs == rhs);
		}

		template <typename T, typename D>
		inline bool operator<(const UniquePtr<T, D> &lhs, const UniquePtr<T, D> &rhs) {
			return std::less<const T *>()(lhs.get(), rhs.get());
		}

		template <typename T, typename D>
		inline bool operator>(const UniquePtr<T, D> &lhs, const UniquePtr<T, D> &rhs) {
			return (rhs < lhs);
		}

		template <typename T, typename D>
		inline bool operator<=(const UniquePtr<T, D> &lhs, const UniquePtr<T, D> &rhs) {
			return !(rhs < lhs);
		}

		template <typename T, typename D>
		inline bool operator>=(const UniquePtr<T, D> &lhs, const UniquePtr<T, D> &rhs) {
			return !(lhs < rhs);
		}
	}
	namespace _29 {
		template <typename T> class SharedPtr;
		template <typename T> void swap(SharedPtr<T> &, SharedPtr<T> &);

		template <typename T>
		class SharedPtr {
			friend void swap<T>(SharedPtr<T> &, SharedPtr<T> &);
		public:
			using element_type = T;

			SharedPtr() : element(nullptr), use(new std::size_t(0)) {}
			SharedPtr(T *p) : element(p), use(new std::size_t(p ? 1 : 0)) {}
			template <typename Deleter>
			SharedPtr(T *p, Deleter d) : element(p), use(new std::size_t(p ? 1 : 0)), del(d) {}
			
			SharedPtr(const SharedPtr &p) : element(p.element), use(p.use), del(p.del) {
				if (p)
					++*use;
			}
			template <typename Deleter>
			SharedPtr(const SharedPtr &p, Deleter d) : element(p.element), use(p.use), del(d) {
				if (p)
					++*use;
			}

			SharedPtr(SharedPtr &&p) noexcept : element(p.element), use(p.use), del(std::move(p.del)) {
				p.element = nullptr;
				p.use = nullptr;
			}

			SharedPtr &operator=(const SharedPtr &rhs) {
				if (this != &rhs) {
					deletion_logic();
					element = rhs.element;
					use = rhs.use;
					del = rhs.del;
					if (element)
						++*use;
				}
				return *this;
			}
			SharedPtr &operator=(SharedPtr &&rhs) noexcept {
				if (this != &rhs) {
					deletion_logic();
					element = rhs.element;
					use = rhs.use;
					del = std::move(rhs.del);
					rhs.element = nullptr;
					rhs.use = nullptr;
				}
				return *this;
			}
			~SharedPtr() {
				deletion_logic();
			}

			std::size_t use_count() const { return *use; }
			bool unique() const { return use_count() == 1; }

			T *get() { return element; }
			const T *get() const { return element; }

			void swap(SharedPtr &s) {
				using std::swap;
				swap(*this, s);
			}

			void reset() {
				deletion_logic();
				element = nullptr;
				use = new std::size_t(0);
				del = std::function<void (T *)>();
			}
			void reset(T *p) {
				deletion_logic();
				element = p;
				if (p)
					use = new std::size_t(1);
				else
					use = new std::size_t(0);
				del = std::function<void (T *)>();
			}
			template <typename Deleter>
			void reset(T *p, Deleter d) {
				deletion_logic();
				element = p;
				if (p)
					use = new std::size_t(1);
				else
					use = new std::size_t(0);
				del = d;
			}

			T &operator*() { return *element; }
			const T &operator*() const { return *element; }
			T *operator->() { return &this->operator*(); }
			const T *operator->() const { return &this->operator*(); }
			explicit operator bool() const { return element; }
		private:
			// Decrement reference count, and if there are no users, delete the pointed-to element
			void deletion_logic() {
				if (use) {
					if (*use == 0) {
						delete use;
					} else if (--*use == 0) {
						del ? del(element) : delete element;
						delete use;
					}
				}
			}

			T *element;
			std::size_t *use;
			std::function<void (T *)> del;
		};

		template <typename T>
		inline void swap(SharedPtr<T> &lhs, SharedPtr<T> &rhs) {
			using std::swap;
			swap(lhs.element, rhs.element);
			swap(lhs.use, rhs.use);
			swap(lhs.del, rhs.del);
		}

		template <typename T>
		inline bool operator==(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return lhs.get() == rhs.get();
		}

		template <typename T>
		inline bool operator!=(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return !(lhs == rhs);
		}

		template <typename T>
		inline bool operator<(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return std::less<const T *>()(lhs.get(), rhs.get());
		}

		template <typename T>
		inline bool operator>(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return (rhs < lhs);
		}

		template <typename T>
		inline bool operator<=(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return !(rhs < lhs);
		}

		template <typename T>
		inline bool operator>=(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return !(lhs < rhs);
		}

		template <typename T, typename... Args>
		SharedPtr<T> MakeShared(Args&&... args) {
			return SharedPtr<T>(new T(std::forward<Args>(args)...));
		}

		template <typename T> class Blob;

		template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);

		template <typename T>
		class Blob {
			friend bool operator==<T>(const Blob<T> &, const Blob<T> &);
		public:
			typedef T value_type;
			typedef typename std::vector<T>::size_type size_type;

			Blob();
			Blob(std::initializer_list<T>);
			template <typename It>
			Blob(It, It);

			typename std::vector<T>::iterator begin() { return data->begin(); }
			typename std::vector<T>::iterator end() { return data->end(); }
			typename std::vector<T>::const_iterator cbegin() const { return data->cbegin(); }
			typename std::vector<T>::const_iterator cend() const { return data->cend(); }

			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }

			void push_back(const T &elem) {	data->push_back(elem); }
			void push_back(T &&elem) { data->push_back(std::move(elem)); }
			void pop_back();
			
			T &front();
			const T &front() const;
			T &back();
			const T &back() const;
			T &operator[](size_type);
			const T &operator[](size_type) const;

		private:
			void check(size_type, const std::string &) const;
			SharedPtr<std::vector<T>> data;
		};

		template <typename T>
		Blob<T>::Blob() : data(MakeShared<std::vector<T>>()) {}

		template <typename T>
		Blob<T>::Blob(std::initializer_list<T> il) : data(MakeShared<std::vector<T>>(il)) {}

		template <typename T>
		template <typename It>
			Blob<T>::Blob(It b, It e) : data(MakeShared<std::vector<T>>(b, e)) {}

		template <typename T>
		void Blob<T>::check(size_type i, const std::string &msg) const {
			if (i >= data->size())
				throw std::out_of_range(msg);
		}

		template <typename T>
		T &Blob<T>::front() {
			check(0, "front on empty Blob");
			return data->front();
		}
		template <typename T>
		const T &Blob<T>::front() const {
			check(0, "front on empty Blob");
			return data->front();
		}
		template <typename T>
		T &Blob<T>::back() {
			check(0, "back on empty Blob");
			return data->back();
		}
		template <typename T>
		const T &Blob<T>::back() const {
			check(0, "back on empty Blob");
			return data->back();
		}
		template <typename T>
		T &Blob<T>::operator[](size_type i) {
			check(i, "subscript out of range");
			return (*data)[i];
		}
		template <typename T>
		const T &Blob<T>::operator[](size_type i) const {
			check(i, "subscript out of range");
			return (*data)[i];
		}
		template <typename T>
		void Blob<T>::pop_back() {
			check(0, "pop back on empty Blob");
			data->pop_back();
		}

		// Equality operators for Blob
		template <typename T>
		bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
			return *lhs.data == *rhs.data;
		}
		template <typename T>
		bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs) {
			return !(lhs == rhs);
		}
	}
	namespace _30 {
		template <typename T> class SharedPtr;
		template <typename T> void swap(SharedPtr<T> &, SharedPtr<T> &);

		template <typename T>
		class SharedPtr {
			friend void swap<T>(SharedPtr<T> &, SharedPtr<T> &);
		public:
			using element_type = T;

			SharedPtr() : element(nullptr), use(new std::size_t(0)) {}
			SharedPtr(T *p) : element(p), use(new std::size_t(p ? 1 : 0)) {}
			template <typename Deleter>
			SharedPtr(T *p, Deleter d) : element(p), use(new std::size_t(p ? 1 : 0)), del(d) {}
			
			SharedPtr(const SharedPtr &p) : element(p.element), use(p.use), del(p.del) {
				if (p)
					++*use;
			}
			template <typename Deleter>
			SharedPtr(const SharedPtr &p, Deleter d) : element(p.element), use(p.use), del(d) {
				if (p)
					++*use;
			}

			SharedPtr(SharedPtr &&p) noexcept : element(p.element), use(p.use), del(std::move(p.del)) {
				p.element = nullptr;
				p.use = nullptr;
			}

			SharedPtr &operator=(const SharedPtr &rhs) {
				if (this != &rhs) {
					deletion_logic();
					element = rhs.element;
					use = rhs.use;
					del = rhs.del;
					if (element)
						++*use;
				}
				return *this;
			}
			SharedPtr &operator=(SharedPtr &&rhs) noexcept {
				if (this != &rhs) {
					deletion_logic();
					element = rhs.element;
					use = rhs.use;
					del = std::move(rhs.del);
					rhs.element = nullptr;
					rhs.use = nullptr;
				}
				return *this;
			}
			~SharedPtr() {
				deletion_logic();
			}

			std::size_t use_count() const { return *use; }
			bool unique() const { return use_count() == 1; }

			T *get() { return element; }
			const T *get() const { return element; }

			void swap(SharedPtr &s) {
				using std::swap;
				swap(*this, s);
			}

			void reset() {
				deletion_logic();
				element = nullptr;
				use = new std::size_t(0);
				del = std::function<void (T *)>();
			}
			void reset(T *p) {
				deletion_logic();
				element = p;
				if (p)
					use = new std::size_t(1);
				else
					use = new std::size_t(0);
				del = std::function<void (T *)>();
			}
			template <typename Deleter>
			void reset(T *p, Deleter d) {
				deletion_logic();
				element = p;
				if (p)
					use = new std::size_t(1);
				else
					use = new std::size_t(0);
				del = d;
			}

			T &operator*() { return *element; }
			const T &operator*() const { return *element; }
			T *operator->() { return &this->operator*(); }
			const T *operator->() const { return &this->operator*(); }
			explicit operator bool() const { return element; }
		private:
			// Decrement reference count, and if there are no users, delete the pointed-to element
			void deletion_logic() {
				if (use) {
					if (*use == 0) {
						delete use;
					} else if (--*use == 0) {
						del ? del(element) : delete element;
						delete use;
					}
				}
			}

			T *element;
			std::size_t *use;
			std::function<void (T *)> del;
		};

		template <typename T>
		inline void swap(SharedPtr<T> &lhs, SharedPtr<T> &rhs) {
			using std::swap;
			swap(lhs.element, rhs.element);
			swap(lhs.use, rhs.use);
			swap(lhs.del, rhs.del);
		}

		template <typename T>
		inline bool operator==(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return lhs.get() == rhs.get();
		}

		template <typename T>
		inline bool operator!=(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return !(lhs == rhs);
		}

		template <typename T>
		inline bool operator<(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return std::less<const T *>()(lhs.get(), rhs.get());
		}

		template <typename T>
		inline bool operator>(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return (rhs < lhs);
		}

		template <typename T>
		inline bool operator<=(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return !(rhs < lhs);
		}

		template <typename T>
		inline bool operator>=(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return !(lhs < rhs);
		}

		template <typename T, typename... Args>
		SharedPtr<T> MakeShared(Args&&... args) {
			return SharedPtr<T>(new T(std::forward<Args>(args)...));
		}

		template <typename T> class Blob;

		template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);

		template <typename T>
		class Blob {
			friend bool operator==<T>(const Blob<T> &, const Blob<T> &);
		public:
			typedef T value_type;
			typedef typename std::vector<T>::size_type size_type;

			Blob();
			Blob(std::initializer_list<T>);
			template <typename It>
			Blob(It, It);

			typename std::vector<T>::iterator begin() { return data->begin(); }
			typename std::vector<T>::iterator end() { return data->end(); }
			typename std::vector<T>::const_iterator cbegin() const { return data->cbegin(); }
			typename std::vector<T>::const_iterator cend() const { return data->cend(); }

			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }

			void push_back(const T &elem) {	data->push_back(elem); }
			void push_back(T &&elem) { data->push_back(std::move(elem)); }
			void pop_back();
			
			T &front();
			const T &front() const;
			T &back();
			const T &back() const;
			T &operator[](size_type);
			const T &operator[](size_type) const;

		private:
			void check(size_type, const std::string &) const;
			SharedPtr<std::vector<T>> data;
		};

		template <typename T>
		Blob<T>::Blob() : data(MakeShared<std::vector<T>>()) {}

		template <typename T>
		Blob<T>::Blob(std::initializer_list<T> il) : data(MakeShared<std::vector<T>>(il)) {}

		template <typename T>
		template <typename It>
			Blob<T>::Blob(It b, It e) : data(MakeShared<std::vector<T>>(b, e)) {}

		template <typename T>
		void Blob<T>::check(size_type i, const std::string &msg) const {
			if (i >= data->size())
				throw std::out_of_range(msg);
		}

		template <typename T>
		T &Blob<T>::front() {
			check(0, "front on empty Blob");
			return data->front();
		}
		template <typename T>
		const T &Blob<T>::front() const {
			check(0, "front on empty Blob");
			return data->front();
		}
		template <typename T>
		T &Blob<T>::back() {
			check(0, "back on empty Blob");
			return data->back();
		}
		template <typename T>
		const T &Blob<T>::back() const {
			check(0, "back on empty Blob");
			return data->back();
		}
		template <typename T>
		T &Blob<T>::operator[](size_type i) {
			check(i, "subscript out of range");
			return (*data)[i];
		}
		template <typename T>
		const T &Blob<T>::operator[](size_type i) const {
			check(i, "subscript out of range");
			return (*data)[i];
		}
		template <typename T>
		void Blob<T>::pop_back() {
			check(0, "pop back on empty Blob");
			data->pop_back();
		}

		// Equality operators for Blob
		template <typename T>
		bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
			return *lhs.data == *rhs.data;
		}
		template <typename T>
		bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs) {
			return !(lhs == rhs);
		}
	}
	namespace _39 {
		template <typename T>
		int compare(const T &v1, const T &v2) {
			if (std::less<T>()(v1, v2)) return -1;
			if (std::less<T>()(v2, v1)) return 1;
			return 0;
		}
	}
	namespace _41 {
		template <typename T1, typename T2>
		auto sum(const T1 &a, const T2 &b) -> decltype(a + b) {
			return a + b;
		}
	}
	namespace _47 {
		template <typename Func, typename T1, typename T2>
		void flip(Func f, T1 &&t1, T2 &&t2) {
			f(std::forward<T2>(t2), std::forward<T1>(t1));
		}
	}
	namespace _48 {
		template <typename T> std::string debug_rep(const T &);
		template <typename T> std::string debug_rep(T *);
		std::string debug_rep(const std::string &);
		std::string debug_rep(char *);
		std::string debug_rep(const char *);

		template <typename T>
		std::string debug_rep(const T &t) {
			std::cout << "debug_rep<T>(const T &)" << std::endl;

			std::ostringstream ret;
			ret << t;
			return ret.str();
		}

		template <typename T>
		std::string debug_rep(T *p) {
			std::cout << "debug_rep<T>(T *)" << std::endl;

			std::ostringstream ret;
			ret << "pointer: " << p;
			if (p)
				ret << " " << debug_rep(*p);
			else
				ret << " null pointer";
			return ret.str();
		}
	}
	namespace _53 {
		template <typename T>
		std::ostream &print(std::ostream &, const T &);

		template <typename T, typename... Args>
		std::ostream &print(std::ostream &, const T &, const Args&...);

		template <typename T>
		std::ostream &print(std::ostream &os, const T &t) {
			return os << t;
		}

		template <typename T, typename... Args>
		std::ostream &print(std::ostream &os, const T &t, const Args& ...rest) {
			os << t << ", ";
			return print(os, rest...);
		}
	}
	namespace _54 {
		class NoOutputOperator {
		public:
			NoOutputOperator(const std::string &s) : data(s) {}
		private:
			std::string data;
		};

		template <typename T>
		std::ostream &print(std::ostream &, const T &);

		template <typename T, typename... Args>
		std::ostream &print(std::ostream &, const T &, const Args&...);

		template <typename T>
		std::ostream &print(std::ostream &os, const T &t) {
			return os << t;
		}

		template <typename T, typename... Args>
		std::ostream &print(std::ostream &os, const T &t, const Args& ...rest) {
			os << t << ", ";
			return print(os, rest...);
		}
	}
	namespace _56 {
		template <typename T>
		std::ostream &print(std::ostream &, const T &);

		template <typename T, typename... Args>
		std::ostream &print(std::ostream &, const T &, const Args&...);

		template <typename T>
		std::ostream &print(std::ostream &os, const T &t) {
			return os << t;
		}

		template <typename T, typename... Args>
		std::ostream &print(std::ostream &os, const T &t, const Args& ...rest) {
			os << t << ", ";
			return print(os, rest...);
		}

		template <typename T> std::string debug_rep(const T &);
		template <typename T> std::string debug_rep(T *);
		std::string debug_rep(const std::string &);
		std::string debug_rep(char *);
		std::string debug_rep(const char *);

		template <typename T>
		std::string debug_rep(const T &t) {
			std::ostringstream ret;
			ret << t;
			return ret.str();
		}

		template <typename T>
		std::string debug_rep(T *p) {
			std::ostringstream ret;
			ret << "pointer: " << p;
			if (p)
				ret << " " << debug_rep(*p);
			else
				ret << " null pointer";
			return ret.str();
		}

		template <typename... Args>
		std::ostream &errorMsg(std::ostream &os, const Args&... rest) {
			return print(os, debug_rep(rest)...);
		}
	}
	namespace _58 {
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
			template <class... Args> void emplace_back(Args&&...);

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

		template <class... Args>
		inline
		void StrVec::emplace_back(Args&&... args) {
			chk_n_alloc();
			alloc.construct(first_free++, std::forward<Args>(args)...);
		}

		bool operator==(const StrVec &, const StrVec &);
		bool operator!=(const StrVec &, const StrVec &);

		bool operator<(const StrVec &, const StrVec &);
		bool operator>(const StrVec &, const StrVec &);
		bool operator<=(const StrVec &, const StrVec &);
		bool operator>=(const StrVec &, const StrVec &);

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
	}
	namespace _61 {
		template <typename T> class SharedPtr;
		template <typename T> void swap(SharedPtr<T> &, SharedPtr<T> &);

		template <typename T>
		class SharedPtr {
			friend void swap<T>(SharedPtr<T> &, SharedPtr<T> &);
		public:
			using element_type = T;

			SharedPtr() : element(nullptr), use(new std::size_t(0)) {}
			SharedPtr(T *p) : element(p), use(new std::size_t(p ? 1 : 0)) {}
			template <typename Deleter>
			SharedPtr(T *p, Deleter d) : element(p), use(new std::size_t(p ? 1 : 0)), del(d) {}
			
			SharedPtr(const SharedPtr &p) : element(p.element), use(p.use), del(p.del) {
				if (p)
					++*use;
			}
			template <typename Deleter>
			SharedPtr(const SharedPtr &p, Deleter d) : element(p.element), use(p.use), del(d) {
				if (p)
					++*use;
			}

			SharedPtr(SharedPtr &&p) noexcept : element(p.element), use(p.use), del(std::move(p.del)) {
				p.element = nullptr;
				p.use = nullptr;
			}

			SharedPtr &operator=(const SharedPtr &rhs) {
				if (this != &rhs) {
					deletion_logic();
					element = rhs.element;
					use = rhs.use;
					del = rhs.del;
					if (element)
						++*use;
				}
				return *this;
			}
			SharedPtr &operator=(SharedPtr &&rhs) noexcept {
				if (this != &rhs) {
					deletion_logic();
					element = rhs.element;
					use = rhs.use;
					del = std::move(rhs.del);
					rhs.element = nullptr;
					rhs.use = nullptr;
				}
				return *this;
			}
			~SharedPtr() {
				deletion_logic();
			}

			std::size_t use_count() const { return *use; }
			bool unique() const { return use_count() == 1; }

			T *get() { return element; }
			const T *get() const { return element; }

			void swap(SharedPtr &s) {
				using std::swap;
				swap(*this, s);
			}

			void reset() {
				deletion_logic();
				element = nullptr;
				use = new std::size_t(0);
				del = std::function<void (T *)>();
			}
			void reset(T *p) {
				deletion_logic();
				element = p;
				if (p)
					use = new std::size_t(1);
				else
					use = new std::size_t(0);
				del = std::function<void (T *)>();
			}
			template <typename Deleter>
			void reset(T *p, Deleter d) {
				deletion_logic();
				element = p;
				if (p)
					use = new std::size_t(1);
				else
					use = new std::size_t(0);
				del = d;
			}

			T &operator*() { return *element; }
			const T &operator*() const { return *element; }
			T *operator->() { return &this->operator*(); }
			const T *operator->() const { return &this->operator*(); }
			explicit operator bool() const { return element; }
		private:
			// Decrement reference count, and if there are no users, delete the pointed-to element
			void deletion_logic() {
				if (use) {
					if (*use == 0) {
						delete use;
					} else if (--*use == 0) {
						del ? del(element) : delete element;
						delete use;
					}
				}
			}

			T *element;
			std::size_t *use;
			std::function<void (T *)> del;
		};

		template <typename T>
		inline void swap(SharedPtr<T> &lhs, SharedPtr<T> &rhs) {
			using std::swap;
			swap(lhs.element, rhs.element);
			swap(lhs.use, rhs.use);
			swap(lhs.del, rhs.del);
		}

		template <typename T>
		inline bool operator==(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return lhs.get() == rhs.get();
		}

		template <typename T>
		inline bool operator!=(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return !(lhs == rhs);
		}

		template <typename T>
		inline bool operator<(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return std::less<const T *>()(lhs.get(), rhs.get());
		}

		template <typename T>
		inline bool operator>(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return (rhs < lhs);
		}

		template <typename T>
		inline bool operator<=(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return !(rhs < lhs);
		}

		template <typename T>
		inline bool operator>=(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs) {
			return !(lhs < rhs);
		}

		template <typename T, typename... Args>
		SharedPtr<T> MakeShared(Args&&... args) {
			return SharedPtr<T>(new T(std::forward<Args>(args)...));
		}

		template <typename T> class Blob;

		template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);

		template <typename T>
		class Blob {
			friend bool operator==<T>(const Blob<T> &, const Blob<T> &);
		public:
			typedef T value_type;
			typedef typename std::vector<T>::size_type size_type;

			Blob();
			Blob(std::initializer_list<T>);
			template <typename It>
			Blob(It, It);

			typename std::vector<T>::iterator begin() { return data->begin(); }
			typename std::vector<T>::iterator end() { return data->end(); }
			typename std::vector<T>::const_iterator cbegin() const { return data->cbegin(); }
			typename std::vector<T>::const_iterator cend() const { return data->cend(); }

			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }

			void push_back(const T &elem) {	data->push_back(elem); }
			void push_back(T &&elem) { data->push_back(std::move(elem)); }
			void pop_back();
			
			T &front();
			const T &front() const;
			T &back();
			const T &back() const;
			T &operator[](size_type);
			const T &operator[](size_type) const;

		private:
			void check(size_type, const std::string &) const;
			SharedPtr<std::vector<T>> data;
		};

		template <typename T>
		Blob<T>::Blob() : data(MakeShared<std::vector<T>>()) {}

		template <typename T>
		Blob<T>::Blob(std::initializer_list<T> il) : data(MakeShared<std::vector<T>>(il)) {}

		template <typename T>
		template <typename It>
			Blob<T>::Blob(It b, It e) : data(MakeShared<std::vector<T>>(b, e)) {}

		template <typename T>
		void Blob<T>::check(size_type i, const std::string &msg) const {
			if (i >= data->size())
				throw std::out_of_range(msg);
		}

		template <typename T>
		T &Blob<T>::front() {
			check(0, "front on empty Blob");
			return data->front();
		}
		template <typename T>
		const T &Blob<T>::front() const {
			check(0, "front on empty Blob");
			return data->front();
		}
		template <typename T>
		T &Blob<T>::back() {
			check(0, "back on empty Blob");
			return data->back();
		}
		template <typename T>
		const T &Blob<T>::back() const {
			check(0, "back on empty Blob");
			return data->back();
		}
		template <typename T>
		T &Blob<T>::operator[](size_type i) {
			check(i, "subscript out of range");
			return (*data)[i];
		}
		template <typename T>
		const T &Blob<T>::operator[](size_type i) const {
			check(i, "subscript out of range");
			return (*data)[i];
		}
		template <typename T>
		void Blob<T>::pop_back() {
			check(0, "pop back on empty Blob");
			data->pop_back();
		}

		// Equality operators for Blob
		template <typename T>
		bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
			return *lhs.data == *rhs.data;
		}
		template <typename T>
		bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs) {
			return !(lhs == rhs);
		}
	}
	namespace _62 {
		class Sales_data;
			std::istream &read(std::istream&, Sales_data&);

		class Sales_data {
			friend std::istream &read(std::istream&, Sales_data&);
			friend std::ostream &print(std::ostream&, const Sales_data&);
			friend Sales_data add(const Sales_data&, const Sales_data&);
			
			friend std::ostream &operator<<(std::ostream &, const Sales_data &);
			friend std::istream &operator>>(std::istream &, Sales_data &);

			friend Sales_data operator+(const Sales_data &, const Sales_data &);
			friend Sales_data operator-(const Sales_data &, const Sales_data &);
			friend Sales_data operator*(const Sales_data &, const Sales_data &);
			friend Sales_data operator/(const Sales_data &, const Sales_data &);

			friend bool operator==(const Sales_data &, const Sales_data &);

			friend struct std::hash<Sales_data>;
		public:
			Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {
				//std::cout << "mainConstructor" << std::endl;
			}
			Sales_data() : Sales_data("", 0, 0) {
				//std::cout << "empty" << std::endl;	
			}
			Sales_data(const std::string &s) : Sales_data(s, 0, 0) {
				//std::cout << "string" << std::endl;
			}
			Sales_data(std::istream &is) : Sales_data() {
				read(is, *this);
				//std::cout << "istream" << std::endl;
			}

			Sales_data &combine(const Sales_data&);
			std::string isbn() const { return bookNo; }
			
			Sales_data &operator+=(const Sales_data &);		// compound-assignment
			Sales_data &operator=(const std::string &);		// copy-assignment operator
			
			explicit operator std::string() const { return bookNo; }
			explicit operator double() const { return revenue; }
		private:
			double avg_price() const;
			std::string bookNo;
			unsigned units_sold = 0;
			double revenue = 0.0;
		};

		std::istream &operator>>(std::istream &, Sales_data &);			// input operator
		std::ostream &operator<<(std::ostream &, const Sales_data &);	// output operator
		Sales_data operator+(const Sales_data &, const Sales_data &);	// addition operator
		Sales_data operator-(const Sales_data &, const Sales_data &);	// subtraction operator
		Sales_data operator*(const Sales_data &, const Sales_data &);	// multiplication operator
		Sales_data operator/(const Sales_data &, const Sales_data &);	// division operator

		Sales_data add(const Sales_data&, const Sales_data&);
		std::ostream &print(std::ostream&, const Sales_data&);

		// inline and constexpr functions should be defined in the class headers
		inline
		double Sales_data::avg_price() const {
			return units_sold ? revenue / units_sold : 0;
		}
	}
	}
}
namespace std {
		template <>
		struct hash<cplusplus_primer::chapter16::_62::Sales_data> {
			typedef size_t result_type;
			typedef cplusplus_primer::chapter16::_62::Sales_data argument_type;
			size_t operator()(const cplusplus_primer::chapter16::_62::Sales_data &s) const {
				return hash<string>()(s.bookNo) ^
					   hash<unsigned>()(s.units_sold) ^
					   hash<double>()(s.revenue);
			}

			hash() = default;
			hash &operator=(const hash &) = default;
		};
}
namespace cplusplus_primer {
	namespace chapter16 {
	namespace _63 {
		template <typename T> std::size_t count_val(const std::vector<T> &, const T &);

		template <typename T>
		std::size_t count_val(const std::vector<T> &vec, const T &val) {
			std::size_t occurence = 0;
			for (const T &elem : vec)
				if (elem == val) ++occurence;
			return occurence;
		}
	}
	namespace _64 {
		template <typename T> std::size_t count_val(const std::vector<T> &, const T);

		template <typename T>
		std::size_t count_val(const std::vector<T> &vec, const T val) {
			std::size_t occurence = 0;
			for (const T &elem : vec)
				if (elem == val) ++occurence;
			return occurence;
		}

		template <>
		std::size_t count_val(const std::vector<const char *> &, const char * const);	
	}
	namespace _65 {
		std::string debug_rep(const std::string &);

		template <typename T> std::string debug_rep(const T &);
		template <typename T> std::string debug_rep(T *);
		template <> std::string debug_rep(char *);
		template <> std::string debug_rep(const char *);

		template <typename T>
		std::string debug_rep(const T &t) {
			std::ostringstream ret;
			ret << t;
			return ret.str();
		}

		template <typename T>
		std::string debug_rep(T *p) {
			std::ostringstream ret;
			ret << "pointer: " << p;
			if (p)
				ret << " " << debug_rep(*p);
			else
				ret << " null pointer";
			return ret.str();
		}
	}
	}
}

#endif
