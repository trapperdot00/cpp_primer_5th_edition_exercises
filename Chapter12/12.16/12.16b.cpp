#include <memory>

int main() {
	std::unique_ptr<int> p(new int());
	std::unique_ptr<int> error;
	error = p;
	return 0;
}
