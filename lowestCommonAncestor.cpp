/**********************************************************
 * Author        : oyjb
 * Email         : jbouyang@126.com
 * Last modified : 2015-07-15 15:16
 * Filename      : lowestCommonAncestor.cpp
 * Description   : copy right for oyjb
 * *******************************************************/
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x),left(NULL),right(NULL){}
};

class Solution
{
	TreeNode *lowestCommonAncestor(TreeNode *root,TreeNode *p,TreeNode *q)
	{
		if (root == NULL || p == root || q == root)
			return root;

		TreeNode *left = lowestCommonAncestor(root->left,p,q);

		TreeNode *right = lowestCommonAncestor(root->right,p,q);
		
		if (left != NULL && right != NULL)
			return root;

		if (left != NULL && right == NULL)
			return left;

		if (left == NULL && right != NULL)
			return right;

		return NULL;
	}
};

int main()
{
	
}
