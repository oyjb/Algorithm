/*
��1+2+��+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ����Լ������ж����
*/

#include <iostream>
/*һ�����ù��캯���Լ���̬���ݳ�Ա*/
class Temp
{
public:
	Temp()
	{
		++N;
		Sum += N;
	}

	static void Reset()
	{
		N = 0;
		Sum = 0;
	}

	static int GetSum()
	{
		return Sum;
	}
private:
	static int N;
	static int Sum;
};

int Temp::N = 0;
int Temp::Sum = 0;

int solution_Sum(int n)
{
	Temp::Reset();

	Temp *a = new Temp[n];
	delete[]a;
	a = 0;

	return Temp::GetSum();
}

int main()
{
	std::cout << solution_Sum(100) << std::endl;
	return 0;
}


/*��������&&��·����
int add_fun(int n, int &sum)
{
	n && add_fun(n - 1, sum);
	return (sum += n);
}

int main()
{
	int sum = 0;
	int n = 100;

	printf("1+2+3+...+n=%d\n", add_fun(n, sum));

	return 0;
}*/