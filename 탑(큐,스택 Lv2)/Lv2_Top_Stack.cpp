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
	for (int j = heights.size() - 1; j >= 0; j--) {
		//�ڱ��ڽŰ� �����ʿ䰡 ���⶧���� ���ϴ°��� �պ��� ���
		for (int i = j - 1; i >= 0; i--) {
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
		//���ÿ� ���ٰ� 0�� �ֱ�
		if (check)
			st.push(0);
		check = true;
	}
	//������ ������ ���信 Ǫ��
	while (!st.empty()) {
		answer.push_back(st.top());
		st.pop();
	}

	return answer;
}

void print(vector<int> heights, vector<int> answer)
{
	vector<int> t = solution(heights);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
		if (answer[i] != t[i])
		{
			cout << "Ʋ��" << endl;
			return;
		}
	}
	cout << "����" << endl;
}

int main()
{
	print({ 6, 9, 5, 7, 4 }, { 0,0,2,2,4 });

	return 0;
}