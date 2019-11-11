#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>

using namespace std;



vector<string> solution(vector<string> record) {
	vector<string> answer;
	//���̵�� �г��� ��ġ
	map<string, string> names;
	string order[3] = { "Enter", "Leave", "Change" };
	string t_order{}, uid{}, name{};
	//���ڿ� ���ҿ�
	stringstream ss;

	for (auto r : record) {
		ss.str(r);
		ss >> t_order;
		//��ɾ Enter Ȥ�� Change��� map�� ���̵�� �̸�����
		if (t_order == order[0] || t_order == order[2]) {
			ss >> uid;
			ss >> name;
			names[uid] = name;
		}
		ss.clear();
	}
	//Enter Ȥ�� Leave��� map���� �̸��� ������ ���
	for (auto r : record) {
		ss.str(r);
		ss >> t_order;
		ss >> uid;
		if (t_order == order[0])
			answer.push_back(names[uid] + "���� ���Խ��ϴ�.");
		else if (t_order == order[1])
			answer.push_back(names[uid] + "���� �������ϴ�.");
		ss.clear();
	}

	return answer;
}

void print(vector<string> record, vector<string> answer) {
	vector<string> t = solution(record);
	if (answer == t)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}

int main() {
	print({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" },
		{ "Prodo���� ���Խ��ϴ�.", "Ryan���� ���Խ��ϴ�.", "Prodo���� �������ϴ�.", "Prodo���� ���Խ��ϴ�." });
	return 0;
}