#include <iostream>
#include <string>

using namespace std;

int main() {
	int a[100][100]{ 0 }, n, sum = 0;
	cin >> n;
	//�迭�� ��ä���
	for (int i = 0, count = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = count++;
		}
	}
	//���Ʒ� �� ���ϱ�
	for (int i = 0; i < n; i++) {
		sum += a[0][i];
		sum += a[n - 1][i];
	}
	//�� �� �׵θ� ���ϱ�(��ġ�� �κ� ����)
	for (int i = 1; i < n - 1; i++) {
		sum += a[i][0];
		sum += a[i][n - 1];
	}
	cout << sum << endl;

	return 0;
}

