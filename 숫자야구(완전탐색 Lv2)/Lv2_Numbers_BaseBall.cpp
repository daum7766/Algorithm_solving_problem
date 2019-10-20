#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<vector<int>> baseball) {
	vector<string> a;
	//�Ҽ� �ִ� ����� �� �߰�
	for (int i = 123; i <= 987; i++) {
		string temp{ to_string(i) };
		if (temp[0] == temp[1] || temp[1] == temp[2] || temp[2] == temp[0] || temp[0] == '0' || temp[1] == '0' || temp[2] == '0')
			continue;
		a.push_back(temp);
	}
	//����� �� Ȯ���ϱ�
	for (auto b : baseball) {
		string temp = to_string(b.at(0));
		for (int i = a.size() - 1; i >= 0; i--) {
			int strike = 0, ball = 0;
			for (int j = 0; j < 3; j++) {
				//��Ʈ����ũ �� üũ
				if (temp[j] == a.at(i)[j])
					strike++;
				//�� �� üũ
				if (temp[j] == a.at(i)[(j + 1) % 3] || temp[j] == a.at(i)[(j + 2) % 3])
					ball++;
			}
			//��Ʈ����ũ�� ���� ���� �����ʴ´ٸ� ����� ������ ����
			if (strike != b.at(1) || ball != b.at(2))
				a.erase(a.begin() + i);
		}
	}
	//���� ����� �� ��ȯ
	return a.size();
}

int main() {

	vector<vector<int>> baseball{ {123, 1, 1}, {356, 1, 0}, {327, 2, 0}, {489, 0, 1} };
	cout << solution(baseball) << endl;
	return 0;
}