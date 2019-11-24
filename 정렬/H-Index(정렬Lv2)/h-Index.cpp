#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end());
	//���� ū���� 0�̶�� H-index �� 0�̴�
	if (!citations.at(citations.size() - 1))
		return 0;
	for (int i = citations.size() - 1, k = 0; i >= 0; i--, k++)	{
		//h-index���� ���̶��
		if (citations.at(i) > k)
			answer = k;
		//�ִ밪�� ����ٸ�
		else{
			answer++;
			break;
		}
		//������ ���� �Դٸ� �����ŭ�� h-index
		if (i == 0)		return citations.size();
	}
	return answer;
}

void print(vector<int> citations, int answer) {
	int t = solution(citations);
	if (t == answer)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}

int main(){
	print({ 3, 0, 6, 1, 5 }, 3);
	print({ 7 },1);
	print({ 1545, 2, 999, 790, 540, 10, 22 }, 6);
	print({22, 47}, 2);
	print({2, 7, 5}, 2);
	print({4, 3, 3, 3, 3}, 3);
	print({10, 50, 100}, 3);
	print({1, 7, 0, 1, 6, 4}, 3);
	print({0}, 0);
	return 0;
}