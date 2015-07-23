/**********************************************************
 * Author        : oyjb
 * Email         : jbouyang@126.com
 * Last modified : 2015-07-22 21:06
 * Filename      : CountCompleteTreeNodes.cpp
 * Description   : copy right for oyjb
 * *******************************************************/
#include <iostream>
using namespace std;

/*
 *计算完全二叉树的节点个数
 */

/*
 * Definition for a binary tree node.
 */
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x),left(NULL),right(NULL){}
};

//非递归算法，耗时76ms，非常快
class Solution
{
public:
	int countNodes(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		int result;              //统计节点个数
		int left_Height;         //存储树的高度，在这里其实就是左子树的高度
		int right_Height;        //存储右子树高度
		TreeNode *visit = root;  //用于遍历树节点
		TreeNode *p = root;
		
		left_Height = 0;
		//树的高度
		while (p != NULL)
		{
			++left_Height;
			p = p->left;
		}
		/*
		 * 根据整棵树的高度，对每一层进行判断
		 * 在任何一层，1、若左子树比右子树高，则继续往左下进入判断
		 *             2、若左右子树等高，则进入右子树判断
		 * 每进入下一层，节点数目翻倍，因为左右两边同样多个节点数
		 */
		result = 1;               //初始化为1
		while (--left_Height)     //当进入循环之后，left_Height已经是左子树的高度，因为减去了1
		{
			result *= 2;         //乘以2
			
			right_Height = 0;
			p = visit->right;
			//计算右子树高度
			while (p != NULL)
			{
				++right_Height;
				p = p->left;
			}
			
			//左子树高
			if (right_Height < left_Height)
				visit = visit->left;
			//左右子树等高
			else
			{
				result += 1;  //可以理解成加上根节点
				visit = visit->right;
			}
		}
		return result;
	}
};

//使用递归法
class Solution
{
public:
	/*--这个方法使用递归，耗时296ms--*/
	int countNodes(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		int left_height = getLeftHeight(root->left);
		int right_height = getLeftHeight(root->right);
		
		/*
		 *第一种情况：左右子树高度相等
		 *这意味着左子树是满二叉树直接计算结果2^h-1,然后加上根节点和右子树节点数
		 */
		if (left_height == right_height)
			return pow(2,left_height) + countNodes(root->right);
		
		/*
		 *第二种情况：左子树比右子树高（只能剩下这种情况）
		 *此时，右子树必然是满二叉树，方法同上
		 */
		return pow(2,right_height) + countNodes(root->left);
	}
	
	/*--计算完全二叉树的高度，一直往左下到尽头，完全二茶树性质--*/
	int getLeftHeight(TreeNode *node)
	{
		int h = 0;
		while (node != NULL)
		{
			++h;
			node = node->left;
		}
		return h;
	}
};

int main()
{
	
	return 0;	
}
