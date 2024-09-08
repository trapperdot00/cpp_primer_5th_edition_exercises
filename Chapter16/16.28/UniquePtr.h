#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H

#include <cstddef>
#include <utility>
#include <functional>

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
		::swap(*this, u);
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

#endif
