#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end());
	//���� ū���� 0�̶�� H-index �� 0�̴�
	if (citations.at(citations.size() - 1) == 0)
	{
		return 0;
	}
	for (int i = citations.size() - 1, k = 0; i >= 0; i--, k++)
	{
		//h-index���� ���̶��
		if (citations.at(i) > k)
			answer = k;
		//�ִ밪�� ����ٸ�
		else
		{
			answer++;
			break;
		}
		//������ ���� �Դٸ� �����ŭ�� h-index
		if (i == 0)
			return citations.size();
	}
	return answer;
}

int main()
{
	vector<int> a = { 3, 0, 6, 1, 5 };
	cout << solution(a) << endl;
	a = { 7 };
	cout << solution(a) << endl;
	a = { 1545, 2, 999, 790, 540, 10, 22 };
	cout << solution(a) << endl;

	return 0;
}