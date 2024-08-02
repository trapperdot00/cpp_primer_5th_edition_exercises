#include <map>
#include <string>
#include <vector>

using std::string;
using std::map;
using std::vector;

int main() {
	map<string, vector<int>> m;
	map<string, vector<int>>::iterator it = m.find("a");
	return 0;
}
