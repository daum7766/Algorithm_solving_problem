#include  <iostream>
#include <list>

using namespace std;

list<int> a;
int lenth = 0;
//������ �Լ�
list<int> Quick_sort(list<int> b)
{
	//����Լ� ��������
	if (b.size() <= 1)
	{
		return b;
	}
	//������ ����
	int pivot = *b.begin();
	b.pop_front();
	int t_lenth = b.size();
	//�ӽú���
	list<int> t_a;
	list<int> t_b;
	//ũ�� ���� ����
	for (int i = 0; i < t_lenth; i++)
	{
		if (pivot >= *b.begin())
		{
			t_a.push_back(*b.begin());
			b.pop_front();
		}
		else
		{
			t_b.push_back(*b.begin());
			b.pop_front();
		}
	}
	//����Լ� ȣ��
	t_a = Quick_sort(t_a);
	t_b = Quick_sort(t_b);
	//���ĵ� �� ��ġ��
	t_a.push_back(pivot);
	t_lenth = t_b.size();
	for (int i = 0; i < t_lenth; i++)
	{
		t_a.push_back(*t_b.begin());
		t_b.pop_front();
	}
	//���ĵ� ����� ��ȯ
	return t_a;
}

int main()
{
	cin >> lenth;
	int t;
	for (int i = 0; i < lenth; i++)
	{
		cin >> t;
		a.push_back(t);
	}
	a = Quick_sort(a);
	for (int i = 0; i < lenth; i++)
	{
		cout << *a.begin() << endl;
		a.pop_front();
	}
	return 0;
}
