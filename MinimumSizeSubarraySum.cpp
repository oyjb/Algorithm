#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int minSubArrayLen(int s, vector<int>& nums)
	{
		int min_len = INT_MAX;
		int n = static_cast<int>(nums.size());
		for (vector<int>::size_type i = 0; i < n; ++i)
		{
			int sum = 0;
			vector<int>::size_type j;
			for (j = i; j < n; ++j)
			{
				sum += nums[j];
				if (sum >= s)
				{
					int len = j - i + 1;
					if (len < min_len)
						min_len = len;
					break;
				}
			}
			//一直累加到最末尾sum都小于s，则外层循环就无需再进行下去了
			if (j == n && sum < s)
				break;
		}
		if (min_len <= n)
			return min_len;

		return 0;
	}
};