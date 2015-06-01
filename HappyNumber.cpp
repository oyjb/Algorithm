/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
#include <iostream>
#include <vector>

//ʹ��C++����
class Solution
{
public:
	bool isHappy(int n)
	{
		std::vector<int> val;
		bool flag = false;
		val.push_back(n); //���vector�洢�Ѿ��������ֵ
		while (n != 0 && n != 1)
		{
			n = getSum(n);
			if (n == 1)
			{
				flag = true;
				break;
			}
			else if (std::find(val.begin(), val.end(), n) != val.end())
				break;
			val.push_back(n);
		}
		if (n == 1)
			flag = true;
		return flag;
	}

	int getSum(int n)
	{
		int sum = 0;
		while (n > 0)
		{
			sum += (n % 10) * (n % 10);
			n /= 10;
		}
		return sum;
	}
};

/*
�����������ù�ϣ��
һ��int����32λ�������01111....11��31��1�������Ϊ2^31-1����ʮλ��
������λ�϶�Ϊ9ʱ��λ�ϵ���ƽ�������λ81*10=810����һ��hash[810]��
�ڶ�ӦΪ�ϵ����������ʹ֮��Ϊ1��0
*/
class Solution
{
public:
	bool isHappy(int n)
	{
		bool flag = false;
		int hash[810];
		int m = n;
		int sum = 0;
		for (int i = 0; i < 1000; ++i)
			hash[i] = 0;
		while (true)
		{
			while (m > 0)
			{
				sum += (m % 10) * (m % 10);
				m /= 10;
			}

			if (sum == 1)
			{
				flag = true;
				break;
			}

			else if (hash[sum] == 1 || sum == n)
			{
				flag = false;
				break;
			}

			hash[sum] = 1;
			m = sum;
			sum = 0;
		}
		return flag;
	}
};