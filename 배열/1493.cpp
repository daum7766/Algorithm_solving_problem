#include <iostream>

using namespace std;

int main() {
	int n, m, temp, arr[100][100]{ 0 }, arr2[100][100]{ 0 };
	cin >> n >> m;
	//�⺻�迭�� ���� �Է¹޴´�.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	//�ι�° �迭�� �������� �ִ� �յ��� ���Ѵ�.
	//ex) 1,1 �̶�� (0, 0), (0, 1), (1, 0), (1, 1)�� �����ش�.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k <= i; k++) {
				for (int z = 0; z <= j; z++) {
					arr2[i][j] += arr[k][z];
				}
			}
		}
	}
	//���� ������ ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}