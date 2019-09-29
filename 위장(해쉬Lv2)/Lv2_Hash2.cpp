#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>//�ؽ��� ���

using namespace std;

int solution(vector<vector<string>> clothes) {
	//���ϱ� ������ �ؾ��ϱ⶧���� �⺻�� 1
	int answer = 1;
	unordered_map<string, int> temp;
	//ū �׵θ��� �з�(��, ����, ����, �ѿ� ��)
	for (int i = 0; i < clothes.size(); i++)
	{
		temp[clothes[i][1]]++;
	}
	//Hash�� ó������ ��ȸ
	for (auto pair : temp)
	{
		//������ �� +1 (�ƹ��͵� �����ʾ�����) �� ��� �����ش�.
		answer *= (pair.second + 1);
	}
	//���� �ϳ��� �Ծ�� �ϹǷ�
	//�ƹ��͵� �������� ����Ǽ� ����
	return answer - 1;
}



int main()
{
	string a[][2] = { {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };
	vector<vector<string>> b;
	for (int i = 0; i < 3; i++)
	{
		b.push_back(vector<string>());
		for (int j = 0; j < 2; j++)
		{
			b.at(i).push_back(a[i][j]);
		}

	}
	cout << solution(b) << endl;
	return 0;
}