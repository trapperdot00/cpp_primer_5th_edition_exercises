#ifndef PTRTOSTRBLOBPTR_H
#define PTRTOSTRBLOBPTR_H

#include "StrBlobPtr.h"

class PtrToStrBlobPtr {
public:
	PtrToStrBlobPtr(StrBlobPtr &sp) : p(&sp) {}
	StrBlobPtr &operator*() const;
	StrBlobPtr *operator->() const;
private:
	StrBlobPtr *p = nullptr;
};

#endif
