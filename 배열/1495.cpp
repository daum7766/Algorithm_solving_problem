#include <iostream>

using namespace std;

int main() {
	int k, n, d[1001][1001]{ 0 }, arr[1001][1001]{ 0 }, x1, x2, y1, y2, u, m;
	cin >> k >> m >> n;
	//n����ŭ�� �����Ͱ� ���´�
	//���Ĵ�� ó���Ѵ�.
	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2 >> u;
		d[x1][y1] += u;
		d[x2 + 1][y2 + 1] += u;
		d[x1][y2 + 1] -= u;
		d[x2 + 1][y1] -= u;
	}
	//�⺻ �迭���� ���
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < m; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//�ð��� �����ϱ� ���� ���ǹ� ���
	//�ڽ��� ���ʰ� ���� ���Ѱſ� i-1 j-1�� ���� �ߺ��� �κ��� ���Ű� �ȴ�.
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < m; j++) {
			if (!i && !j)	arr[i][j] = d[i][j];
			else if (!i)	arr[i][j] = arr[i][j - 1] + d[i][j];
			else if (!j)	arr[i][j] = arr[i - 1][j] + d[i][j];
			else	arr[i][j] = arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1] + d[i][j];
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}