#include <vector>
#include <list>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::list;

int main() {
	list<int> li(10, 1);
	vector<int> vi(10, 2);
	vector<double> vd1(li.begin(), li.end());
	vector<double> vd2(vi.begin(), vi.end());
	for (const double &d : vd1)
		cout << d << " ";
	cout << '\n';
	for (const double &d : vd2)
		cout << d << " ";
	cout << endl;
	return 0;
}
