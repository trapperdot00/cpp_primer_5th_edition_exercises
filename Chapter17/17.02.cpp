#include <tuple>
#include <string>
#include <vector>
#include <utility>

using std::tuple;
using std::string;
using std::vector;
using std::pair;

int main() {
	tuple<string, vector<string>, pair<string, int>>
			t{"hi", {"a", "b", "c", "d"}, {"hello", 5}};
	return 0;
}
