#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	//�� �ο�����ŭ ���͸� �����ϰ� ü�������� 1�� ����
	vector<int> check(n, 1);
	//ü������ �Ҿ���� ����� 1�� ���̳ʽ�
	for (auto l : lost)		check.at(l - 1)--;
	//ü������ �������� �����Դٸ� 1�� �÷���
	for (auto r : reserve)		check.at(r - 1)++;
	//ó������ ���鼭 ��ȸ�ϱ�
	for (int i = 0; i < check.size(); i++) {
		//ü������ 0�����
		if (check.at(i) == 0) {
			//���� ����� ������ �ֳ� Ȯ���ϰ� �ִٸ� ������
			if (i != check.size() - 1 && check.at(i + 1) == 2) {
				check.at(i + 1)--;
				check.at(i)++;
			}
			//�ڿ� ����� ������ �ֳ� Ȯ���ϰ� �ִٸ� ������
			else if (i != 0 && check.at(i - 1) == 2) {
				check.at(i - 1)--;
				check.at(i)++;
			}
		}
	}
	//ü������ ����� �ֳ� üũ�ϱ�
	for (auto a : check)
		if (a != 0)	answer++;

	return answer;
}

void print(int n, vector<int> lost, vector<int> reserve)
{
	cout << solution(n, lost, reserve) << endl;
}


int main() {

	print(7, { 2, 3, 4 }, { 1, 2, 3, 6 });
	print(5, { 2, 4 }, { 1, 3, 5 });
	print(5, { 2, 4 }, { 3 });
	print(3, { 3 }, { 1 });

	return 0;
}