#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	stack<int> st;
	bool check = true;
	//����Ʈ�� �ڿ������� ��ȸ�ϱ�
	for (int j = heights.size() - 1; j >= 0; j--)
	{
		//�ڱ��ڽŰ� �����ʿ䰡 ���⶧���� ���ϴ°��� �պ��� ���
		for (int i = j - 1; i >= 0; i--)
		{
			//���ϵڿ������� �տ�Ÿ���� ū���
			if (heights.at(i) > heights.at(j))
			{
				//���ÿ� ���° Ÿ������ �ֱ�
				st.push(i + 1);
				//���ǹ� ��Ȱ��ȭ
				check = false;
				//�ݺ��� ������
				break;
			}
		}
		//���� ���Ϳ��� ū�Ծ��ٸ�
		if (check)
		{
			//���ÿ� ���ٰ� 0�� �ֱ�
			st.push(0);
		}
		check = true;
	}
	//������ ������ ���信 Ǫ��
	while (!st.empty())
	{
		answer.push_back(st.top());
		st.pop();
	}

	return answer;
}

int main()
{
	vector<int> a = { 6, 9, 5, 7, 4 };

	vector<int> b = solution(a);
	for (int i = 0; i < b.size(); i++)
	{
		cout << b.at(i) << endl;
	}

	return 0;
}