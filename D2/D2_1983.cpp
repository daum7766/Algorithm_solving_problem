#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	//�� �ݺ� Ƚ��
	int length;
	//������ ���� ���
	string answer[10]{ "A+", "A0", "A-" , "B+", "B0", "B-", "C+", "C0", "C-", "D0" };
	cin >> length;
	for (int i = 1; i <= length; i++) {
		//���� ,���л���, �л���ȣ
		int grade[3], n, k;
		//�л� ��ȣ�ϰ� ������ �����ϱ����� vector
		vector<pair<double, int> > student;
		cin >> n >> k;
		//���� �Է¹ޱ�
		for (int z = 0; z < n; z++) {
			for (int j = 0; j < 3; j++)
				cin >> grade[j];
			//������ ���� �Ѽ����� �л���ȣ ���
			student.push_back(make_pair(grade[0] * 0.35 + grade[1] * 0.45 + grade[2] * 0.2, z));
		}
		//�����ϱ�(�������� ������ Gcc 4.8.5�������� �����ʾƼ� reverse���)
		sort(student.begin(), student.end());
		reverse(student.begin(), student.end());
		for (int j = 0; j < student.size(); j++) {
			if (student[j].second == k - 1)//�׳� ������ 0~1�����̱⶧���� *10���ؼ� �����ش�.
				cout << "#" << i << " " << answer[(j * 10) / student.size()] << endl;
		}
	}
	return 0;
}