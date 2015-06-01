class Solution
{
public:
	int countPrimes(int n) {
		bool *Del = new bool[n]; // ����Ƿ񱻻�ȥ
		Del[2] = false;

		for (int i = 3; i<n; ++i)
		if (i % 2 == 0)
			Del[i] = true;  // 2�ı���ȫ����ȥ
		else
			Del[i] = false;

		for (int i = 3; i<n; i += 2)
		if (!Del[i])  // ֮���һ��δ����ȥ
		{
			//if(i*i>n)  break;  // ��ǰ������ƽ������n������ѭ��
			for (int j = 2; i*j<n; ++j)
				Del[i*j] = true;
		}

		int count = 0;
		for (int i = 2; i<n; ++i)
		if (!Del[i])
			++count;

		delete[] Del;
		return count;
	}
};