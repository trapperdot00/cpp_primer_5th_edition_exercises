#include <string>

using std::string;

string (&func())[10];

int main() {
	return 0;
}
