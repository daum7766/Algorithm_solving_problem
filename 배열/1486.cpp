#include <iostream>

using namespace std;

int main() {
	int a[100][100]{ 0 }, n, m, reverse = 1;
	cin >> n >> m;
	int row = -1, col = m - 1;
	int limit = 0;
	//�ѹݺ��� Ƚ���� n*m�� ���ڱ���
	for (int count = 1; count <= m * n;) {
		//���� ä���
		for (int i = 0; i < n - limit; i++) {
			row += reverse;
			a[row][col] = count++;
		}
		//�ݺ��� �ѹ��ɶ����� ������Ų��.
		reverse = -reverse;
		//����ä���
		for (int i = 0; i < m - limit - 1; i++) {
			col += reverse;
			a[row][col] = count++;
		}
		//�ִ� �ݺ�Ƚ�� ����
		limit++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}
