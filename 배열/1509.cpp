#include <iostream>

using namespace std;

int main() {
	//11*10 �迭
	int arr[11][10]{ 0 };
	//�� �Է¹ޱ�
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
		}
	}
	//�����ϸ鼭üũ�ϱ�
	for (int j = 0; j < 10; j++) {
		for (int i = 9; i >= 0; i--) {
			//���� ����ִٸ� �н��ϱ�
			if (!arr[10][j]) 		break;
			//������� ����, �������������ٸ� safe���
			if (!arr[i][j]) {
				if (!i)	cout << j + 1 << " safe" << endl;
				continue;
			}
			//�忡���� �����ٸ� crash����ϰ� �������� �Ѿ��
			else if (arr[i][j] > 0) {
				cout << j + 1 << " crash" << endl;
				break;
			}
			//�����̸� �����ٸ� fall�� ����ϰ� �������� �Ѿ��
			else if (arr[i][j] < 0) {
				cout << j + 1 << " fall" << endl;
				break;
			}
		}
	}
	return 0;
}