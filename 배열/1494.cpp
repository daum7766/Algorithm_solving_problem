#include <iostream>

using namespace std;

int main() {
	int k, n, arr[101]{ 0 }, arr2[101]{ 0 }, arr3[3];
	cin >> k >> n;
	//n����ŭ�� �����Ͱ� ���´�
	for (int i = 1; i <= n; i++) {
		//�����ʹ� s, e, u ������ ���´�.
		cin >> arr3[0] >> arr3[1] >> arr3[2];
		//d[s] = d[s] + u;
		arr[arr3[0]] = arr[arr3[0]] + arr3[2];
		//d[e+1] = d[e+1] - u;
		arr[arr3[1] + 1] = arr[arr3[1] + 1] - arr3[2];
	}
	//1���� �迭���� ����ϱ�
	for (int i = 1; i <= k; i++)		cout << arr[i] << " ";
	cout << endl;
	for (int i = 1; i <= k; i++) {
		//���� ������ + ����迭���¸� ���ϰ� ���
		arr2[i] = arr2[i - 1] + arr[i];
		cout << arr2[i] << " ";
	}
	return 0;
}