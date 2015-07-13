/**********************************************************
 * Author        : oyjb
 * Email         : jbouyang@126.com
 * Last modified : 2015-07-12 21:39
 * Filename      : countDigitOne.cpp
 * Description   : copy right for oyjb
 * *******************************************************/
#include <iostream>

using namespace std;

class Solution
{
public:

	int countDigitOne(int n)
	{
		int count = 0;
		/*
		 * 针对n的每一位数进行统计1的个数
		 * 其中m为计算每一位数时的基数，比如个位时m为1
		 * 十位时m为10，百位时m为100，以此类推
		 */
		for (long m = 1; m <= n; m *= 10)
		{
			long x = n / m;

			long a = x / 10;  //a为当前位数前的数字

			long b = x % 10;  //b为当前位的数字

			long c = n % m;   //c为当前基数下的余数

			/*--第一种情况，当前位数字为0--*/
			if (b == 0)
				count += a * m;

			/*--第二种情况，当前位数字为1--*/
			else if (b == 1)
				count += a * m + (c + 1);

			/*--第三种情况，当前位数字大于1--*/
			else
				count += (a + 1) * m;
		}
		return count;
	}
};

int main()
{
	int n = 10000000;
	Solution s;
	int count = s.countDigitOne(n);
	cout << "1 de ge shu wei : " << count << endl;

	return 0;
}
