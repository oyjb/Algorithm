/**********************************************************
 * Author        : oyjb
 * Email         : jbouyang@126.com
 * Last modified : 2015-07-18 12:03
 * Filename      : ProductofArrayExceptSelf.cpp
 * Description   : copy right for oyjb
 * *******************************************************/
/*
 * 给定一个数组nums，要求返回：
 * 一个数组ret，这个数组在ret[i]位置上的值为nums数组上除了元素nums[i]以外的所有元素的乘积
 * 而且要求算法时间复杂度为O(n),空间复杂度为O(1)
 */
#include<iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> productExceptSel(vector<int>& nums)
	{
		int len = static_cast<int>(nums.size());
		vector<int> ret(len,1);  //存储最终返回的数组,同时初始化为1

		int temp = 1;
		/*--第一个for循环计算nums[i]的左侧部分元素的乘积并乘到对应ret[i]上--*/
		for (int i = 1; i < len; ++i)
		{
			temp *= nums[i-1];
			/*--temp始终存储着当前nums数组位置上左侧元素的乘积--*/
			ret[i] *= temp;
		}
		
		temp = 1;
		/*--第二个for循环计算nums[i]的右侧部分元素的乘积并乘到对应ret[i]上--*/
		for (int i = len - 2; i >= 0; --i)
		{
			temp *= nums[i+1];
			/*--temp始终存储着当前nums数组位置上右侧元素的乘积--*/
			ret[i] *= temp;
		}
		return ret;
	}
};

int main()
{
	Solution s;
	vector<int> vec = {1,2,3,4};
	vector<int> result = s.productExceptSel(vec);
	cout << "[ ";
	for (auto it = result.cbegin(); it != result.cend(); ++it)
 		cout << *it << " ";
	cout << "]" << endl;;
	return 0;
}
