#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int answer = 9;

void dfs(int N, int number, int count, int currentNumber) {
	//����Ƚ�� �̻󰬴ٸ� ����
	if (count >= 9)		return;
	//������� number�� ���ٸ� ����Ƚ���� answer�� ������ ����
	if (currentNumber == number) {
		answer = min(answer, count);
		return;
	}
	int tempNumber = 0;
	//�ִ� N�� ���Ƚ���� 9�������̹Ƿ� �̶����� �ݺ�
	for (int i = 0; i < 9 + count; i++) {
		//N���� NN,NNN,NNNN .....
		tempNumber = tempNumber * 10 + N;
		//���ϱ� ���� ���ϱ� ������ dfs ���
		dfs(N, number, count + 1 + i, currentNumber + tempNumber);
		dfs(N, number, count + 1 + i, currentNumber - tempNumber);
		dfs(N, number, count + 1 + i, currentNumber * tempNumber);
		dfs(N, number, count + 1 + i, currentNumber / tempNumber);
	}
}

int solution(int N, int number) {
	dfs(N, number, 0, 0);
	//answer�� 9��� ���� number�� �´� ��찡 ������ ���̹Ƿ� -1 ����
	if (answer == 9)	return -1;
	return answer;
}

void print(int n, int number, int answer) {
	int t = solution(n, number);
	if (t == answer)		cout << "����" << endl;
	else		cout << "Ʋ��" << endl;
	::answer = 9;
}

int main() {
	print(5, 12, 4);
	print(2, 11, 3);
	print(5, 31168, -1);
	return 0;
}