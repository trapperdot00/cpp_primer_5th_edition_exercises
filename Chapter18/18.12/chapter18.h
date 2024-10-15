#ifndef CHAPTER18_H
#define CHAPTER18_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <utility>
#include <stdexcept>
#include <iostream>
#include <cstddef>
#include <functional>

namespace cplusplus_primer {
	namespace chapter18 {
	namespace _07 {
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
			template <typename It> Blob(It, It);

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
		Blob<T>::Blob()
		try : data(std::make_shared<std::vector<T>>()) {}
		catch (const std::bad_alloc &err) {
			std::cerr << err.what() << std::endl;
		}

		template <typename T>
		Blob<T>::Blob(std::initializer_list<T> il)
		try : data(std::make_shared<std::vector<T>>(il)) {}
		catch (const std::bad_alloc &err) {
			std::cerr << err.what() << std::endl;
		}

		template <typename T>
		template <typename It>
		Blob<T>::Blob(It b, It e)
		try : data(std::make_shared<std::vector<T>>(b, e)) {}
		catch (const std::bad_alloc &err) {
			std::cerr << err.what() << std::endl;
		}

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
		BlobPtr<T>::BlobPtr()
		try : curr(0) {}
		catch (const std::exception &err) {
			std::cerr << err.what() << std::endl;
		}

		template <typename T>
		BlobPtr<T>::BlobPtr(Blob<T> &a, std::size_t sz)
		try : wptr(a.data), curr(sz)  {}
		catch (const std::exception &err) {
			std::cerr << err.what() << std::endl;
		}
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
		ConstBlobPtr<T>::ConstBlobPtr()
		try : curr(0) {}
		catch (const std::exception &err) {
			std::cerr << err.what() << std::endl;
		}

		template <typename T>
		ConstBlobPtr<T>::ConstBlobPtr(const Blob<T> &a, std::size_t sz)
		try : wptr(a.data), curr(sz) {}
		catch (const std::exception &err) {
			std::cerr << err.what() << std::endl;
		}
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
	namespace _08 {
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

			Blob() noexcept(false);
			Blob(std::initializer_list<T>) noexcept(false);
			template <typename It> Blob(It, It) noexcept(false);

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
		Blob<T>::Blob() noexcept(false)
		try : data(std::make_shared<std::vector<T>>()) {}
		catch (const std::bad_alloc &err) {
			std::cerr << err.what() << std::endl;
		}

		template <typename T>
		Blob<T>::Blob(std::initializer_list<T> il) noexcept(false)
		try : data(std::make_shared<std::vector<T>>(il)) {}
		catch (const std::bad_alloc &err) {
			std::cerr << err.what() << std::endl;
		}

		template <typename T>
		template <typename It>
		Blob<T>::Blob(It b, It e) noexcept(false)
		try : data(std::make_shared<std::vector<T>>(b, e)) {}
		catch (const std::bad_alloc &err) {
			std::cerr << err.what() << std::endl;
		}

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
			BlobPtr() noexcept;
			BlobPtr(Blob<T> &, std::size_t = 0) noexcept;

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
		BlobPtr<T>::BlobPtr() noexcept
		try : curr(0) {}
		catch (const std::exception &err) {
			std::cerr << err.what() << std::endl;
		}

		template <typename T>
		BlobPtr<T>::BlobPtr(Blob<T> &a, std::size_t sz) noexcept
		try : wptr(a.data), curr(sz)  {}
		catch (const std::exception &err) {
			std::cerr << err.what() << std::endl;
		}
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
			ConstBlobPtr() noexcept;
			ConstBlobPtr(const Blob<T> &, std::size_t = 0) noexcept;

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
		ConstBlobPtr<T>::ConstBlobPtr() noexcept
		try : curr(0) {}
		catch (const std::exception &err) {
			std::cerr << err.what() << std::endl;
		}

		template <typename T>
		ConstBlobPtr<T>::ConstBlobPtr(const Blob<T> &a, std::size_t sz) noexcept
		try : wptr(a.data), curr(sz) {}
		catch (const std::exception &err) {
			std::cerr << err.what() << std::endl;
		}
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
	namespace _09 {
		class out_of_stock : public std::runtime_error {
		public:
			explicit out_of_stock(const std::string &s) : std::runtime_error(s) {}
		};

		class isbn_mismatch : public std::logic_error {
		public:
			explicit isbn_mismatch(const std::string &s) : std::logic_error(s) {}
			isbn_mismatch(const std::string &s, const std::string &l, const std::string &r)
				: std::logic_error(s), left(l), right(r) {}
			const std::string left, right;
		};

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
	struct hash<cplusplus_primer::chapter18::_09::Sales_data> {
		typedef size_t result_type;
		typedef cplusplus_primer::chapter18::_09::Sales_data argument_type;
		size_t operator()(const cplusplus_primer::chapter18::_09::Sales_data &s) const {
			return hash<string>()(s.bookNo) ^
				   hash<unsigned>()(s.units_sold) ^
				   hash<double>()(s.revenue);
		}

		hash() = default;
		hash &operator=(const hash &) = default;
	};
}
namespace cplusplus_primer {
	namespace chapter18 {
	namespace _10 {
		class out_of_stock : public std::runtime_error {
		public:
			explicit out_of_stock(const std::string &s) : std::runtime_error(s) {}
		};

		class isbn_mismatch : public std::logic_error {
		public:
			explicit isbn_mismatch(const std::string &s) : std::logic_error(s) {}
			isbn_mismatch(const std::string &s, const std::string &l, const std::string &r)
				: std::logic_error(s), left(l), right(r) {}
			const std::string left, right;
		};

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
	struct hash<cplusplus_primer::chapter18::_10::Sales_data> {
		typedef size_t result_type;
		typedef cplusplus_primer::chapter18::_10::Sales_data argument_type;
		size_t operator()(const cplusplus_primer::chapter18::_10::Sales_data &s) const {
			return hash<string>()(s.bookNo) ^
				   hash<unsigned>()(s.units_sold) ^
				   hash<double>()(s.revenue);
		}

		hash() = default;
		hash &operator=(const hash &) = default;
	};
}

#endif
