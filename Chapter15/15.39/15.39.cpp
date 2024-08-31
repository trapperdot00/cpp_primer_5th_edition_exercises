#include "AllQuery.h"

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

int main() {
	ifstream is("text.txt");
	TextQuery tq(is);
	Query q = Query("fiery") & Query("bird") | Query("wind");
	print(cout, q.eval(tq));
	cout << q.rep() << endl;
	return 0;
}
