#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<vector<int>> baseball) {
	vector<string> a;
	//�Ҽ� �ִ� ����� �� �߰�
	for (int i = 123; i <= 987; i++) {
		string temp{ to_string(i) };
		if (temp[0] == temp[1] || temp[1] == temp[2] || temp[2] == temp[0] ||
			temp[0] == '0' || temp[1] == '0' || temp[2] == '0')
			continue;
		a.push_back(temp);
	}
	//����� �� Ȯ���ϱ�
	for (auto b : baseball) {
		string temp = to_string(b[0]);
		for (int i = a.size() - 1; i >= 0; i--) {
			int strike = 0, ball = 0;
			for (int j = 0; j < 3; j++) {
				//��Ʈ����ũ �� üũ
				if (temp[j] == a[i][j])		strike++;
				//�� �� üũ
				if (temp[j] == a[i][(j + 1) % 3] || temp[j] == a[i][(j + 2) % 3])
					ball++;
			}
			//��Ʈ����ũ�� ���� ���� �����ʴ´ٸ� ����� ������ ����
			if (strike != b[1] || ball != b[2])		a.erase(a.begin() + i);
		}
	}
	//���� ����� �� ��ȯ
	return a.size();
}

void print(vector<vector<int>> baseball, int answer) {
	int t = solution(baseball);
	if (t == answer)		cout << "����" << endl;
	else	cout << "����" << endl;

}

int main() {
	print({ 123, 1, 1 }, { 356, 1, 0 }, { 327, 2, 0 }, { 489, 0, 1 }, 2);
	return 0;
}