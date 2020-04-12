#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	//�� �ο�����ŭ ���͸� �����ϰ� ü�������� 1�� ����
	vector<int> check(n, 1);
	//ü������ �Ҿ���� ����� 1�� ���̳ʽ�
	for (auto l : lost)		check[l - 1]--;
	//ü������ �������� �����Դٸ� 1�� �÷���
	for (auto r : reserve)		check[r - 1]++;
	//ó������ ���鼭 ��ȸ�ϱ�
	for (size_t i = 0; i < check.size(); i++) {
		//ü������ 0�����
		if (!check[i]) {
			//���� ����� ������ �ֳ� Ȯ���ϰ� �ִٸ� ������
			if (i != check.size() - 1 && check[i + 1] == 2) {
				check[i + 1]--;
				check[i]++;
			}
			//�ڿ� ����� ������ �ֳ� Ȯ���ϰ� �ִٸ� ������
			else if (i && check[i - 1] == 2) {
				check[i - 1]--;
				check[i]++;
			}
		}
	}
	//ü������ ����� �ֳ� üũ�ϱ�
	for (auto a : check)
		if (a != 0)	answer++;
	return answer;
}

void print(int n, vector<int> lost, vector<int> reserve, int answer) {
	int t = solution(n, lost, reserve);
	if (t == answer)		cout << "����" << endl;
	else		cout << "Ʋ��" << endl;
}

int main() {
	print(5, { 2, 4 }, { 1, 3, 5 }, 5);
	print(5, { 2, 4 }, { 3 }, 4);
	print(3, { 3 }, { 1 }, 2);
	print(7, { 2, 3, 4 }, { 1, 2, 3, 6 }, 6);
	return 0;
}