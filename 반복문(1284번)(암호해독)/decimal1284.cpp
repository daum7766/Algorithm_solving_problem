#include <iostream>
#include <cmath>
using namespace std;

bool Decheck(int a)
{
	int i = 2;
	while (1) { //���ѷ��� 
		if (i <= sqrt(a)) {
			if (a % i == 0) { //i�� ����������� �Ҽ��� �ƴ� 
				return false;
			}
			else {
				i++;
			}
		}
		else { //i�� j���� Ŀ�������� ����������� ������ �Ҽ� 
			return true;
		}
	}
}

int main()
{
	int num;
	cin >> num;
	for (int i = 2; i < num; i++)
	{
		if (Decheck(i))
		{
			if (num % i == 0 && Decheck(num / i))
			{
				cout << i << " " << num / i << endl;
				return 0;
			}
		}
	}
	cout << "wrong number" << endl;
	return 0;
}
