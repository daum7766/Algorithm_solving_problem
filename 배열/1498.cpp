#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	//������ ����, ���� ����, �迭
	int length, g, a[100]{ 1000 };
	cin >> length >> g;
	//�Է¹ޱ�
	for (int i = 0; i < length; i++) 	cin >> a[i];
	//g��ŭ�� ������Ű�� �ݺ�
	for (int i = 0; i < length; i += g) {
		int num = a[i];
		//������ŭ �ݺ�ó��
		for (int j = 0; j < g; j++) {
			//������ �������� ũ�⸦�Ѿ�ٸ� ����
			if (i + j >= length)	break;
			//������ ã��
			num = min(num, a[i + j]);
		}
		cout << num << " ";
	}
	return 0;
}