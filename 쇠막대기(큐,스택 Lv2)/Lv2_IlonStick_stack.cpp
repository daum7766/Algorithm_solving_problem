#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int solution(string arrangement) {

	int answer = 0;
	stack<int> num;
	//������ ó������ ���������� ��ȸ
	for (int i = 0; i < arrangement.length(); i++)
	{
		//���� ��ȣ��� ���ÿ� �߰�
		if (arrangement[i] == '(')
		{
			num.push(1);
		}
		else
		{
			//�ݴ� ��ȣ��� ���ÿ��� �ϳ�����
			num.pop();
			//�� ��ȣ�� ���� ��ȣ���ٸ� �������̹Ƿ� ������ȣ��ŭ �����߰�
			if (arrangement[i - 1] == '(')
			{
				answer += static_cast<int>(num.size());
			}
			else//�� ��ȣ�� ���� ��ȣ�� �ƴϾ��ٸ� �踷����� �������̹Ƿ� 1�� �߰�
			{
				answer++;
			}
		}
	}
	return answer;
}

int main()
{
	string a = "()(((()())(())()))(())";
	cout << solution(a) << endl;
	return 0;
}