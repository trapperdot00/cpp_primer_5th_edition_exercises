#ifndef BASE_H
#define BASE_H

class Base {
public:
	void pub_mem();

	void memfcn(Base &b) { b = *this; }
protected:
	int prot_mem;
private:
	char priv_mem;
};

#endif
