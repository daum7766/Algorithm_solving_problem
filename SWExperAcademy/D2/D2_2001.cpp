#include <iostream>
#include <string>
using namespace std;
int main() {
	//�� �ݺ�����, ĭ����, �ĸ�äũ��, �ִ븮��Ʈ
	int length, n, m, list[15][15];
	cin >> length;
	//�� �ݺ���ŭ
	for (int i = 1; i <= length; i++) {
		int max = 0;
		cin >> n >> m;
		//�ĸ������� �Է¹޴´�.
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cin >> list[j][k];
			}
		}
		//�����ʰ� �Ʒ��� �̵��ϸ鼭 �ĸ����� ���Ͽ� �ִ��ĸ��� ���
		for (int j = 0; j <= n - m; j++) {
			for (int k = 0; k <= n - m; k++) {
				//��������� �ĸ�ä �̵�
				int sum = 0;
				//������Ͱ� �ĸ��� ���ϱ�
				for (int x = j; x < j + m; x++) {
					for (int y = k; y < k + m; y++) {
						sum += list[x][y];
					}
				}
				//�ִ밪�� ���Ͽ� ��ũ�ٸ� �ٲٱ�
				if (sum > max)        max = sum;
			}
		}
		cout << "#" << i << " " << max << endl;
	}
	return 0;
}