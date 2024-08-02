#ifndef TREENODE_H
#define TREENODE_H

#include <string>

class TreeNode {
public:
	TreeNode();
	TreeNode(const TreeNode &);
	TreeNode &operator=(const TreeNode &);
	~TreeNode();

	int use_count() const { return *count; }
private:
	std::string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};

#endif
