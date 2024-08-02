#ifndef HASPTR_H
#define HASPTR_H

#include <string>
#include <cstddef>

class HasPtr {
public:
	HasPtr(const std::string & = std::string());
	HasPtr(const HasPtr &);
	HasPtr &operator=(const HasPtr &);
	~HasPtr();

	std::size_t use_count() const { return *use; }

private:
	std::string *ps;
	int i;
	std::size_t *use;
};

#endif
