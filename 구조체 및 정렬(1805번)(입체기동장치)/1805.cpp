#include <iostream>

using namespace std;

struct MyStruct
{
	int num;
	int gas;
};

//������
void Quick_Sort(MyStruct* data, int start, int end)
{
	if (start >= end)
	{
		//���Ұ� 1�� ������ ��� ���ȣ�� ����
		return;
	}

	int pivot = start;
	int i = pivot + 1;
	int j = end;
	MyStruct temp;

	while (i <= j)
	{
		//i�� ������ ���ų� ���������� ���������� i����
		while (i <= end && data[i].num <= data[pivot].num)
		{
			i++;
		}
		//j�� ó������ ���ų� ���������� Ŭ������ j ����
		while (j > start && data[j].num >= data[pivot].num)
		{
			j--;
		}

		if (i > j)
		{
			//�����Ͱ� �����ȴٸ� �����ĳ� pivot ��ȯ
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else
		{
			//i��°�� j��°�� ��ü
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	//���ȣ��
	Quick_Sort(data, start, j - 1);
	Quick_Sort(data, j + 1, end);
}

MyStruct myStructs[100];

int main()
{
	int a, b, length = 0;
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		cin >> a >> b;
		myStructs[i].num = a;
		myStructs[i].gas = b;
	}
	Quick_Sort(myStructs, 0, length - 1);
	for (int i = 0; i < length; i++)
	{
		cout << myStructs[i].num << " " << myStructs[i].gas << endl;
	}


	return 0;
}