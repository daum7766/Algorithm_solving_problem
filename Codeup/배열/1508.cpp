#include <iostream>

using namespace std;

int main() {
	int arr[20][21]{ 0 }, len;
	//���α��� �Է�
	cin >> len;
	//������ �ޱ�
	for (int i = 0; i < len; i++) 	cin >> arr[i][0];
	//������ ���
	//���ʵ����Ϳ��� �������� �����͸� ���ش�
	for (int i = 1; i < len; i++) {
		for (int j = 1; j <= i; j++) {
			arr[i][j] = arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}
	//������ ���
	for (int i = 0; i < len; i++) {
		for (int j = 0; j <= i; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	return 0;
}