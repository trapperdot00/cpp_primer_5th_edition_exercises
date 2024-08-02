#ifndef BINSTRTREE_H
#define BINSTRTREE_H

#include "TreeNode.h"

class BinStrTree {
public:
	BinStrTree();
	BinStrTree(const BinStrTree &);
	BinStrTree &operator=(const BinStrTree &);
	~BinStrTree();

private:
	TreeNode *root;
};

#endif
