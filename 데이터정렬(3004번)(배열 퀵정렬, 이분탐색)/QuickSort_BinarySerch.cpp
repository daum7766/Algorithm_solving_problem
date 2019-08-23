#include <iostream>

using namespace std;
int t_array[50000];
int temp[50000];

//������
void Quick_Sort(int* data, int start, int end)
{
	if (start >= end)
	{
		//���Ұ� 1�� ������ ��� ���ȣ�� ����
		return;
	}

	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int temp;

	while (i <= j)
	{
		//i�� ������ ���ų� ���������� ���������� i����
		while (i <= end && data[i] <= data[pivot])
		{
			i++;
		}
		//j�� ó������ ���ų� ���������� Ŭ������ j ����
		while (j > start && data[j] >= data[pivot])
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

int BinarySerch(int* data, int targetNum, int start, int end)
{
	int pivot = (start + end) / 2;
	if (targetNum == data[pivot])
	{
		return pivot;
	}
	else if (targetNum < data[pivot])
	{
		return BinarySerch(data, targetNum, start, pivot - 1);
	}
	else if (targetNum > data[pivot])
	{
		return BinarySerch(data, targetNum, pivot + 1, end);
	}
}

int main()
{
	int length;
	cin >> length;
	int t;
	for (int i = 0; i < length; i++)
	{
		cin >> t;
		t_array[i] = t;
		temp[i] = t;
	}
	Quick_Sort(t_array, 0, length - 1);

	for (int i = 0; i < length; i++)
	{
		cout << BinarySerch(t_array, temp[i], 0, length) << " ";
	}

	return 0;
}