#include <iostream>
#include <string>

using namespace std;

int main() {
	string a;
	int sum{};
	cin >> a;
	//�ݺ����� �̿��ؼ� �ѱ��ھ� ����;
	//char�� -'0'�� �ϸ� ���ڰ� �ȴ�.
	for (auto t : a) 	sum += t - '0';
	//sum�� 3���� �������� 0�̶�� 3�� ����̴�.
	if (!(sum % 3))	cout << 1 << endl;
	else	cout << 0 << endl;
	return 0;
}