#include <string>
#include <vector>
#include <iostream>

using namespace std;

int bitcheck(int k) {
	int count = 0;
	//k�� 0�̵ɶ����� �ݺ�
	while (k) {
		//k�� 1�� ��Ʈ����(Ȧ���� ��)
		if (k & 1)	count++;
		//k�� ����Ʈ-> ������ 2�� ����
		k >>= 1;
	}
	return count;
}

int solution(int n) {
	int answer = n;
	//�Է°� 1�� �������ϱ�
	int bit = bitcheck(n);
	//�Էµ� ��Ʈ���� 1�� ������ �������ϸ� ����
	while (true)
		if (bit == bitcheck(++answer))
			break;
	return answer;
}

void print(int n, int answer) {
	int t = solution(n);
	if (answer == t)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}

int main() {
	print(78, 83);
	print(15, 23);
	return 0;
}
