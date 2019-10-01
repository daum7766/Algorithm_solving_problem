#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array1, vector<vector<int>> commands) {
	vector<int> answer;

	//������
	int start;
	//��������
	int end;
	//ã�ƾ��ϴ� ��ȣ
	int index;
	//��ȯ�ǾߵǴ� ��Ʈ���� �ݺ�
	for (int i = 0; i < commands.size(); i++)
	{
		//�ӽ� ���� ����
		vector<int> temp;
		//�ʿ��� ���Ǻ��� �Ҵ�
		start = commands[i][0] - 1;
		end = commands[i][1];
		index = commands[i][2] - 1;
		//�ʿ��� �κи� �ӽú��Ϳ� ����
		for (int j = start; j < end; j++)
		{
			temp.push_back(array1[j]);
		}
		//�ӽ� ��������
		sort(temp.begin(), temp.end());
		//�ӽú����� index��°�� answer�� ����
		answer.push_back(temp.at(index));
	}

	return answer;
}

int main()
{
	int arr[] = { 1, 5, 2, 6, 3, 7, 4 };
	int arr2[][3] = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };
	vector<int> temp;
	vector<vector<int>> temp2;
	for (int i = 0; i < 7; i++)
	{
		temp.push_back(arr[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		vector<int> t;
		for (int j = 0; j < 3; j++)
		{
			t.push_back(arr2[i][j]);
		}
		temp2.push_back(t);
	}

	vector<int> result = solution(temp, temp2);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result.at(i) << " ";
	}
	return 0;
}