/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

������ע���Ƕ�������������ν���������������������ϵĽڵ�ֵ��ԶС�ڸ��ڵ��ֵ�����������ϵĽڵ�ֵ��Զ���ڸ��ڵ��ֵ�����һ�����ϵ����нڵ㶼�������㡣

�������ջ��ʵ�֡�ʼ�ձ���ջ���ڵ�ֵ����С�ġ�����ĿҪ��next()��hasNext()������ʱ�临�Ӷȱ���ΪO(1)���ռ临�Ӷ�ΪO(h)��
����ζ�Ų���һ���԰����нڵ�洢��ջ��Ȼ�����ζ�ȡ������Ϊ����һ�ö��������������ö������������ص㣬���ǳ�ʼ��ֻ�洢������·���ϵĽڵ㣬Ȼ�����ζ�ȡջ����Сֵ��
ÿ��ȡһ�Σ����Ѹýڵ���Һ��ӽڵ�洢��ջ�ϣ������Ϳ��Խ�����ת�������������ˡ�������������Ȼ�ظ��������ϵ������������Ϳ���ÿ�ζ�����ջ�����ΪO(h)��
��ȡջ����Сֵ��ʱ�临�Ӷ�Ҳ�Ƚ�С����Ϊ�����ǰѽӽ���ײ�Ľڵ���к��Ӷ�Ӧ��������·���ϵĽڵ�ѹ��ջ�ϡ�

������ʵ�ִ��룬����Ƚ������İ�
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