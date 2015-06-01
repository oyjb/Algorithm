/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

分析：注意是二叉搜索树。所谓二叉搜索树就是左子树上的节点值永远小于根节点的值，而右子树上的节点值永远大于根节点的值。这对一棵树上的所有节点都必须满足。

则可以用栈来实现。始终保持栈顶节点值是最小的。但题目要求next()和hasNext()函数的时间复杂度必须为O(1)，空间复杂度为O(h)。
这意味着不能一次性把所有节点存储到栈上然后依次读取。但因为这是一棵二叉搜索树，运用二叉搜索树的特点，我们初始化只存储左子树路径上的节点，然后依次读取栈顶最小值，
每读取一次，都把该节点的右孩子节点存储至栈上，这样就可以紧接着转入右子树处理了。在右子树上依然重复左子树上的做法。这样就可以每次都保持栈的深度为O(h)，
而取栈顶最小值的时间复杂度也比较小，因为仅仅是把接近最底层的节点的有孩子对应的左子树路径上的节点压入栈上。

下面是实现代码，还算比较清晰的吧
*/
#include <iostream>
#include <stack>
/**
* Definition for binary TreeNode
**/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator
{
public:
	BSTIterator(TreeNode *root)
	{
		storeTreeNode(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext()
	{
		return (!BST_Iterator.empty());
	}

	/** @return the next smallest number */
	int next()
	{
		TreeNode *min = BST_Iterator.top();
		BST_Iterator.pop();

		/*store the rightchiled's TreeNode*/
		if (min->right != NULL)
			storeTreeNode(min->right);

		return min->val;
	}

	/** @store letf TreeNode */
	void storeTreeNode(TreeNode *p)
	{
		TreeNode *q = p;
		while (q != NULL)
		{
			BST_Iterator.push(q);
			q = q->left;
		}
	}

private:
	std::stack<TreeNode*> BST_Iterator;
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/