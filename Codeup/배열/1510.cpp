#include <iostream>

using namespace std;

int main() {
	int arr[50][50]{ 0 }, n, count = 0;
	cin >> n;
	//ù�࿡ ���� �߰�
	int x = 0, y = n / 2;
	for (int i = 0; i < n * n; i++) {
		count++;
		//x�� ������ �������ٸ� ��������
		if (x < 0)	x += n;
		//���� �������� �Ѿ�ٸ� ù����
		if (y >= n)	y -= n;
		arr[x][y] = count;
		//n�� ������ ������
		if (count % n == 0) {
			x++;
			continue;
		}
		//�న�� ������
		x--;
		y++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	return 0;
}