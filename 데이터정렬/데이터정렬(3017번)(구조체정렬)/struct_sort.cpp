#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct Student
{
	int num;
	int math;
	int information;
};

Student students[1001];
bool compare(const Student& st1, const Student& st2)
{
	if (st1.math < st2.math)
	{
		return true;
	}
	else if (st1.math > st2.math)
	{
		return false;
	}
	else
	{
		if (st1.information < st2.information)
		{
			return true;
		}
		else if (st1.information > st2.information)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}


int main()
{
	int length;
	int t_math;
	int t_information;
	//VS���� �׽�Ʈ�Ѵٸ� scanf_s�� ����
	scanf("%d", &length);
	for (int i = 0; i < length; i++)
	{
		scanf("%d %d", &t_math, &t_information);
		students[i].num = i + 1;
		students[i].math = t_math;
		students[i].information = t_information;
	}
	//sort�� ������� ������ �������߹Ƿ� stableSort�� �̿�
	stable_sort(students, students + length, compare);
	for (int i = length - 1; i >= 0; i--)
	{
		printf("%d %d %d\n", students[i].num, students[i].math, students[i].information);
	}

	return 0;
}
