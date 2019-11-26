#include <vector>
#include <iostream>//���� ��¿�
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	//�����ڰ� ��¹��
	vector<vector<int>> math{ {1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5} };
	// ���� ��� ������� �׽�Ʈ
	vector<int> count = { 0, 0, 0 };
	for (int i = 0; i < answers.size(); i++) {
		// ������ �� ��ȣ�� ���Ͽ� ī��Ʈ ����
		if (answers.at(i) == math.at(0).at(i % math.at(0).size()))	count[0]++;
		if (answers.at(i) == math.at(1).at(i % math.at(1).size()))	count[1]++;
		if (answers.at(i) == math.at(2).at(i % math.at(2).size()))	count[2]++;
	}
	//���� ���� ����ã��
	int max = *max_element(count.begin(), count.end());
	//���� ���� ������ ���� ��� ã�Ƽ� ���信 �߰�, �տ��� ���� �߰��߱⶧���� ���� �ʿ����
	for (int i = 0; i < 3; i++)
		if (max == count[i])	answer.push_back(i + 1);
	return answer;
}

void print(vector<int> answers, vector<int> answer) {
	vector<int> t = solution(answers);
	if (t == answer)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}

int main() {
	print({ 1,2,3,4,5 }, {1});
	print({ 1,3,2,4,2 }, {1,2,3});
	print({ 4, 1, 1, 4, 3, 4, 3, 1, 4, 2 }, { 1, 2 });
	return 0;
}