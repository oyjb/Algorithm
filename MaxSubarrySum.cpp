/**
求子数组的最大和
这是一道很常见的算法题，很多人都能很快的写出算法，但很多人都不能写得完全正确，问题主要出在sum初始化上，
很多错误的答案将他初始化为0，如果数组的所有元素都为负，那么得到的最大最是0，sum要初始化成数组的第一个元素。
**/

/*求子数组的最大和*/
int maxSum(int *arr, int len)
{
	int sum, max;
	sum = max = arr[0];
	for (int i = 1; i < len; ++i)
	{
		if (sum <= 0)
			sum = arr[i];
		else
			sum += arr[i];
		if (sum > max)
			max = sum;
	}
	return max;
}
