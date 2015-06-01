/**
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

在设计算法过程中，要注意实现的时间和空间复杂度，最好不要用排序等操作避免time limited。

可以采取的思想是：

每次push的时候：都与最小值比较，保持min是最小值

每次pop的时候：检查“栈顶”是否恰好为最小值，若是，则我们的存储最小值的变量需要更新。若不是，则可以放心的进行pop操作。

整个过程可以采用list或vector等顺序容器进行模拟栈的实现。
*/

#include <list>
/*下面是我的实现*/

class MinStack
{
public:

	MinStack()
	{
		min = INT_MAX;
	}

	/* 在push过程中始终保持min是最小值 */
	void push(int x)
	{
		if (x<min) min = x;
		min_Stack.push_back(x);
	}

	/* 在pop过程中需检查栈顶元素是否是最小值，若是，需重新更新min值 */
	void pop()
	{
		if (min_Stack.back() == min)
		{
			min_Stack.pop_back();
			min = INT_MAX;
			std::list<int>::iterator it = min_Stack.begin();
			while (it != min_Stack.end())
			{
				if (*it<min) min = *it;
				it++;
			}
		}
		else
			min_Stack.pop_back();
	}

	int top()
	{
		return min_Stack.back();
	}

	int getMin()
	{
		return min;
	}
private:
	std::list<int> min_Stack;
	int min;
};

/*
但是以上的算法实现并没有满足supports push, pop, top, and retrieving the minimum element in constant time.
---常量时间，即复杂度为O(1)
所以应该改写，看下别人的算法是怎么做的吧
*/
#include <stack>

class MinStack
{
public:
	MinStack() = default;

	void push(int x)
	{
		int min = INT_MIN;
		if (stk.size() > 0)
			min = stk.top().second;

		if (stk.size() == 0 || x < min)
			stk.push(std::make_pair(x, x));

		else
			stk.push(std::make_pair(x, min));
	}

	void pop()
	{
		stk.pop();
	}

	int top()
	{
		return stk.top().first;
	}

	int GetMin()
	{
		return stk.top().second;
	}

private:
	std::stack<std::pair<int, int>> stk;
};