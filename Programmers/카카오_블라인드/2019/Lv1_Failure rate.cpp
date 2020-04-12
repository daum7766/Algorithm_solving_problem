#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

bool compare(pair<int, double>& a, pair<int, double>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	sort(stages.begin(), stages.end());
	vector<pair<int, double>> percent;	//������������ �������� ������
	map<int, int> stagesClear;	//�� ���������� �ӹ��� �ο� 
	int pCount = stages.size();	//�������� Ŭ���� �ο���
	for (int j = 0; j < stages.size(); j++)	//�������� Ŭ���� �ο��� �и�
		stagesClear[stages[j]]++;
	for (int i = 1; i <= N; i++) {		//1������������ N������������ ��ȸ
		if (!pCount || !stagesClear[i])//���������� �����ο�/�� �ο����� ����
			percent.push_back({ i, 0 });
		else
			percent.push_back({ i, (double)stagesClear[i] / pCount });
		pCount -= stagesClear[i];		//�������� �ο��鸸ŭ ����
	}
	sort(percent.begin(), percent.end(), compare);//������������ ����
	for (auto p : percent)		//���信 �ű��
		answer.push_back(p.first);
	return answer;
}

void print(int N, vector<int> stages, vector<int> answer) {
	vector<int> t = solution(N, stages);
	if (answer == t)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}

int main() {

	print(4, { 2,2,2,2,2 }, { 2,1,3,4 });
	print(4, { 4,4,4,4,4 }, { 4,1,2,3 });
	print(5, { 2,1,2,6,2,4,3,3 }, { 3,4,2,1,5 });
	return 0;
}
