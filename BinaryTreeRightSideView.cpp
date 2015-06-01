/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
 5     4        <---
You should return [1, 3, 4].
*/
/*Definition for binary tree*/
#include <iostream>
#include <vector>
struct TreeNode
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	std::vector<TreeNode*> rightSideView(TreeNode *root)
	{
		std::vector<TreeNode*> right_side;
		rightSide(root, right_side, 0);
		return right_side;
	}
	void rightSide(TreeNode *r, std::vector<TreeNode*> &a, int i)
	{
		if (r == NULL)
			return;
		if (i == a.size())
			a.push_back(r->val);
		rightSide(r->right, a, i + 1);
		rightSide(r->left, a, i + 1);
	}
};