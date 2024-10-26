#ifndef FINAL_H
#define FINAL_H

#include "MI.h"
#include "Class.h"

class Final : public MI, public Class {
public:
	Final() : Base(), MI(), Class() {}
	Final(int i) : Base(i), MI(i), Class() {}
	Final(const Final &f) : Base(f), MI(f) {}
};

#endif
