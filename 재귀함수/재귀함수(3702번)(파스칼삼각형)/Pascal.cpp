#include <iostream>
using namespace std;

int pa[51][51];

int Recursion(int r, int c)
{
	if (pa[r][c])//���� �����Ͱ� �ִٸ�
	{
		return pa[r][c];
	}
	if (r == 1 || c == 1)	//�⺻���� ���� ���� Ȥ�� �������� 1
	{
		return 1;
	}
	return pa[r][c] = (Recursion(r - 1, c) + Recursion(r, c - 1)) % 100000000;

}


int main()
{
	int r;
	int c;
	cin >> r >> c;
	cout << Recursion(r, c) << endl;
	return 0;
}