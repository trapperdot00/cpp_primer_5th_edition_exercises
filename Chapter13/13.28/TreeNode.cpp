#include "TreeNode.h"

TreeNode::TreeNode() : value(""), count(new int(1)), left(nullptr), right(nullptr) { }
TreeNode::TreeNode(const TreeNode &t) : value(t.value), count(t.count), left(t.left), right(t.right) { ++*count; }
TreeNode &TreeNode::operator=(const TreeNode &rhs) {
	++*rhs.count;
	if (--*count == 0) {
		delete count;
		delete left;
		delete right;
	}
	value = rhs.value;
	count = rhs.count;
	left = rhs.left;
	right = rhs.right;
	return *this;
}
TreeNode::~TreeNode() {
	if (--*count == 0) {
		delete count;
		delete left;
		delete right;
	}
}
