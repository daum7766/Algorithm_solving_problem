#include <iostream>

using namespace std;

int main() {
	//�迭ũ��, ������x, ������y, 2�����迭, ����1, ����2
	int n, x, y, arr[100][100], x1, y1;
	cin >> n >> x >> y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//x,y��ǥ���� ��������ŭ ���ؼ� ����Ѵ�.
			//��ǥ�� 0�̾ƴ϶� 1���ͽ����ϹǷ� 1���� ���ش�.
			//���� 0�� �ƴ϶� 1���� �����ϹǷ� ������� 1�� �����ش�.
			x1 = abs(x - 1 - i);
			y1 = abs(y - 1 - j);
			arr[i][j] = x1 + y1 + 1;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}