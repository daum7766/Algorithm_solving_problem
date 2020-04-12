#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<string>> answerlist;

void dfs(vector<vector<string>>& tickets, vector<pair<int, int>>& useCheck, string from, int count) {
	//�������� Ƽ���� ��δ� ����ߴٸ�
	if (count == tickets.size()) {
		//�����ĺ� ����
		vector<string> answer;
		//���� ������ �ٲ�� �ȵǱ⶧���� �ӽ÷� �ϳ� ���� �� ����
		vector<pair<int, int>> temp = useCheck;
		sort(temp.begin(), temp.end());
		//������� ���信�߰�
		for (auto a : temp)		answer.push_back(tickets[a.second][0]);
		//������ �༺���� ���� �߰�����
		answer.push_back(tickets[temp[temp.size() - 1].second][1]);
		//���丮��Ʈ�� �߰��ϰ� ����
		answerlist.push_back(answer);
		return;
	}
	for (int i = 0; i < tickets.size(); i++) {
		//����� ����Ƽ���̰� �༱���� ������
		if (useCheck[i].second == -1 && tickets[i][0] == from) {
			//����ߴٰ� �����ϰ�
			useCheck[i] = { count, i };
			//�����
			dfs(tickets, useCheck, tickets[i][1], count + 1);
			//����� �������� ����ߴٴ� ���� ����
			useCheck[i] = { 0, -1 };
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	//��뿩�θ� ������ �ӽú��� (����, �ε�����ȣ)
	vector<pair<int, int>> useCheck(tickets.size(), { 0 , -1 });
	//ó���� ICN���� ����ؾ� �Ѵ�.
	dfs(tickets, useCheck, "ICN", 0);
	//���ĺ� ������ ��ȯ�ؾ� �ϱ⶧���� ����
	sort(answerlist.begin(), answerlist.end());
	//���� �տ��ִ°��� ���ĺ� ������ ���ĵ� ���̴�.
	return answerlist[0];
}

void print(vector<vector<string>> tickets, vector<string> answer) {
	vector<string> t = solution(tickets);
	if (t == answer)		cout << "����" << endl;
	else		cout << "Ʋ��" << endl;
	answerlist.clear();
}

int main() {
	print({ {"ICN","JFK"}, {"HND", "IAD"}, {"JFK", "HND"} }, { "ICN", "JFK", "HND", "IAD" });
	print({ {"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"} }, { "ICN", "ATL", "ICN", "SFO", "ATL", "SFO" });
	return 0;
}