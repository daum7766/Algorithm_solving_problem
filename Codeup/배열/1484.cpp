#include <iostream>

using namespace std;

int main() {
	int a[100][100]{ 0 }, n, m, row = 0, col = -1, reverse = 1;
	cin >> n >> m;
	int limit = 0;
	//�ѹݺ��� Ƚ���� n*m�� ���ڱ���
	for (int count = 1; count <= n * m;) {
		//����ä���
		for (int i = 0; i < m - limit; i++) {
			col += reverse;
			a[row][col] = count++;
		}
		//���� ä���
		for (int i = 0; i < n - limit - 1; i++) {
			row += reverse;
			a[row][col] = count++;
		}
		//�ִ� �ݺ�Ƚ�� ����
		limit++;
		//�ݺ��� �ѹ��ɶ����� ������Ų��.
		reverse = -reverse;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}