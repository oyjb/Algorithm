/**
�������������
����һ���ܳ������㷨�⣬�ܶ��˶��ܺܿ��д���㷨�����ܶ��˶�����д����ȫ��ȷ��������Ҫ����sum��ʼ���ϣ�
�ܶ����Ĵ𰸽�����ʼ��Ϊ0��������������Ԫ�ض�Ϊ������ô�õ����������0��sumҪ��ʼ��������ĵ�һ��Ԫ�ء�
**/

/*�������������*/
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