/**********************************************************
 * Author        : oyjb
 * Email         : jbouyang@126.com
 * Last modified : 2015-06-25 13:10
 * Filename      : invertTree.cpp
 * Description   : 
 * *******************************************************/
/*
 * Definition for a binary tree node.
 * struct TreeNode
 * {
 * 		int val;
 * 		TreeNode *left;
 * 		TreeNode *right;
 * 		TreeNode(int x) : val(x),left(NULL),right(NULL){}
 * };
 */
class Solution
{
public:
	TreeNode* invertTree(TreeNode* root)
	{	
		if (root == NULL)
			return root;
		//change leftNode and right node.
		if (root->left != NULL || root->right != NULL)
		{
			TreeNode *t = root->left;
			root->left = root->right;
			root->right = t;
		}
		invertTree(root->left);
		invertTree(root->right);

		return root;
	}
};
