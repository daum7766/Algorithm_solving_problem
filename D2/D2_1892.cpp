#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int length, m_length, t, count = 1;
	//�� �ݺ��� Ƚ��
	cin >> length;
	while (length--) {
		//���� �Է¹޴� Ƚ��
		cin >> m_length;
		//���Ϳ� ����Ʈ�� ����
		vector<int> list;
		//
		long long answer = 0;
		//��� �Է��� vector�� �߰�
		while (m_length--) {
			cin >> t;
			list.push_back(t);
		}
		//������ �ɰ��� ����(������ ���� �������κ�)
		int max = *--list.end();
		//������ ������ ������ ó������ �ݺ��Ѵ�.
		for (int i = list.size() - 2; i >= 0; i--) {
			//���ذ����� ������� �̵��߰�
			if (list[i] <= max)      	answer += max - list[i];
			//�ƴ϶�� ���ذ� ����
			else      max = list[i];
		}
		cout << "#" << count++ << " " << answer << endl;
	}
	return 0;
}