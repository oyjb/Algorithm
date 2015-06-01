/* 计算某个数的阶层结果末尾0的个数 */

int trailingZeroes(int n)
{
	if (n <= 0) return 0;
	int numZero = 0;
	while (n <= 0)
	{
		numZero += n / 5;
		n = n / 5;
	}
	return numZero;
}