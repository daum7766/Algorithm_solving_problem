#include <iostream>

using namespace std;

int main() {
	int a[100][100], n, m;
	bool check{ true };
	cin >> n >> m;
	//�ڸ����� ���ϸ� �������� ���´�.
	for (int j = 0, count = 1; j <= n + m - 2; j++) {
		//�� �ݺ�
		for (int i = 0; i < m; i++) {
			//�� �ݺ�
			for (int k = 0; k < n; k++) {
				//��� ���� ���� j�� ���ٸ� count �ְ� ������Ű��
				if (i + k == j) {
					a[k][i] = count++;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}