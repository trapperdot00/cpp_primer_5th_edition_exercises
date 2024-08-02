#ifndef HASPTR_H
#define HASPTR_H

#include <string>
#include <iostream>

class HasPtr {
	friend void swap(HasPtr &, HasPtr &);
	friend std::ostream &print(std::ostream &, const HasPtr &);
public:
	HasPtr(const std::string & = std::string());
	HasPtr(const HasPtr &);
	HasPtr(HasPtr &&) noexcept;
	HasPtr &operator=(const HasPtr &);
	HasPtr &operator=(HasPtr &&) noexcept;
	~HasPtr();

	bool operator<(const HasPtr &rhs) const { return *ps < *rhs.ps; }
private:
	std::string *ps;
	int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
	std::cout << "swapping " << *lhs.ps << " and " << *rhs.ps << std::endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

#endif
