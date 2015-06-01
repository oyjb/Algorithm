/**
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

������㷨�����У�Ҫע��ʵ�ֵ�ʱ��Ϳռ临�Ӷȣ���ò�Ҫ������Ȳ�������time limited��

���Բ�ȡ��˼���ǣ�

ÿ��push��ʱ�򣺶�����Сֵ�Ƚϣ�����min����Сֵ

ÿ��pop��ʱ�򣺼�顰ջ�����Ƿ�ǡ��Ϊ��Сֵ�����ǣ������ǵĴ洢��Сֵ�ı�����Ҫ���¡������ǣ�����Է��ĵĽ���pop������

�������̿��Բ���list��vector��˳����������ģ��ջ��ʵ�֡�
*/

#include <list>
/*�������ҵ�ʵ��*/

class MinStack
{
public:

	MinStack()
	{
		min = INT_MAX;
	}

	/* ��push������ʼ�ձ���min����Сֵ */
	void push(int x)
	{
		if (x<min) min = x;
		min_Stack.push_back(x);
	}

	/* ��pop����������ջ��Ԫ���Ƿ�����Сֵ�����ǣ������¸���minֵ */
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
�������ϵ��㷨ʵ�ֲ�û������supports push, pop, top, and retrieving the minimum element in constant time.
---����ʱ�䣬�����Ӷ�ΪO(1)
����Ӧ�ø�д�����±��˵��㷨����ô���İ�
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