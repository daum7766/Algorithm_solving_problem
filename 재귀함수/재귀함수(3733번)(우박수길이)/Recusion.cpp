#include <iostream>
#include <map>
#define MAX 10000000

using namespace std;

unsigned short list[MAX + 1] = { 1,1,2 };
int count;

int Recursion(long long n)
{
	if (n <= MAX && list[n])//�̹̰���ߴٸ� �ѱ��
	{
		return list[n];
	}
	if (n % 2 == 1)//Ȧ��
	{
		//�迭���̸� �Ѿ�� ���� ����
		if (n > MAX)
		{
			return Recursion((3 * n) + 1) + 1;
		}
		else//�޸������̼�
		{
			return list[n] = Recursion((3 * n) + 1) + 1;
		}

	}
	else//¦��
	{
		//�迭���̸� �Ѿ�� ���� ����
		if (n > MAX)
		{
			return Recursion(n / 2) + 1;
		}
		else//�޸������̼�
		{
			return list[n] = Recursion(n / 2) + 1;
		}

	}
}

int main()
{
	int a, b;
	int index = 0, max = 0;
	cin >> a >> b;
	for (int i = b; i >= a; i--)
	{
		if (Recursion(i) > max)
		{
			index = i;
			max = Recursion(i);
		}
		else if (Recursion(i) == max)
		{
			index = i;
		}
	}
	cout << index << " " << max << endl;

	return 0;

}