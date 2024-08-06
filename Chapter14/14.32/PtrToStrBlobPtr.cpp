#include "PtrToStrBlobPtr.h"

StrBlobPtr &PtrToStrBlobPtr::operator*() const {
	return *p;
}

StrBlobPtr *PtrToStrBlobPtr::operator->() const {
	return &this->operator*();
}
