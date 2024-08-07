#ifndef EQUAL_H
#define EQUAL_H

class Equal {
public:
	Equal(int i) : val(i) {}
	bool operator()(int) const;
private:
	int val;
};

#endif
