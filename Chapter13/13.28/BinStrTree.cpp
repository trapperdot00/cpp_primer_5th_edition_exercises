#include "BinStrTree.h"

BinStrTree::BinStrTree() : root(new TreeNode()) { }
BinStrTree::BinStrTree(const BinStrTree &b) : root(new TreeNode(*b.root)) { }
BinStrTree &BinStrTree::operator=(const BinStrTree &rhs) {
	TreeNode *newRoot = new TreeNode(*rhs.root);
	delete root;
	root = newRoot;
	return *this;
}
BinStrTree::~BinStrTree() {
	delete root;
}
