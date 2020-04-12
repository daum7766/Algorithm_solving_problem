#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool memo[1000000]{ false };
/*
�޸��� ���̼ǰ�
�����佺�״Ͻ��� ü�� �̿��� ����Ǯ��
*/

int solution(int n) {
	int answer = 0;
	for (int i = 2; i <= n; i++) {
		//� ���� ������ٸ� �Ҽ��� �ƴϹǷ� �н�
		if (memo[i - 1])		continue;
		//���� ������ �ǳʿԴٸ� �Ҽ��� �ƴϹǷ� ī��Ʈ ����
		answer++;
		//������� ������� N���� �ڽ��� ����� �Ҽ��� �ƴѰ����� ��ȯ
		for (int j = i + i; j <= n; j += i)		memo[j - 1] = true;
	}
	return answer;
}

void print(int n, int answer) {
	int t = solution(n);
	if (answer == t)	cout << "����" << endl;
	else	cout << "Ʋ��" << endl;
}

int main() {
	print(10, 4);
	print(5, 3);
	return 0;
}