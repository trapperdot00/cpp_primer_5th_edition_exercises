#include "BinStrTree.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	BinStrTree a;
	BinStrTree b = a;
	{
		BinStrTree c = b;
	}

	TreeNode aa, dd;
	cout << aa.use_count() << '\t' << dd.use_count() << endl;
	TreeNode bb = aa;
	cout << aa.use_count() << '\t' << dd.use_count() << '\t' << bb.use_count() << endl;
	dd = aa;
	cout << aa.use_count() << '\t' << dd.use_count() << '\t' << bb.use_count() << endl;
	{
		TreeNode cc = bb;
		cout << aa.use_count() << '\t' << dd.use_count() << '\t' << bb.use_count() << '\t' << cc.use_count() << endl;
	}
	cout << aa.use_count() << '\t' << dd.use_count() << '\t' << bb.use_count() << '\t' << endl;
	return 0;
}
