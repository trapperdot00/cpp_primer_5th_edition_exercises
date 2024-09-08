#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include <cstddef>
#include <utility>
#include <functional>

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
		::swap(*this, s);
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

#endif
