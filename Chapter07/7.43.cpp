

class NoDefault {
public:
	NoDefault(int i) : num(i) {}
private:
	int num;
};

class C {
public:
	C() : element(0) {}
private:
	NoDefault element;
};

int main() {
	return 0;
}
