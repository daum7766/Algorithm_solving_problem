#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	//���� ��ô��
	queue<int> current;
	//ť�� �ű��
	for (auto p : progresses)
		current.push(p);
	while (!current.empty()) {
		//��ô�� �߰�
		for (int i = 0; i < current.size(); i++) {
			int p = current.front();
			current.pop();
			current.push(p + speeds.at(i));
		}
		int count = 0;
		//ť ���ΰ˻�
		while (true) {
			//��ô���� 100�ۼ�Ʈ �̻��̶�� ť���� �����ϰ� ī��Ʈ ����
			if (current.size() > 0 && current.front() >= 100) {
				current.pop();
				speeds.erase(speeds.begin());
				count++;
				continue;
			}
			break;
		}
		//ī��Ʈ�� �Ѱ��̻� �ö󰬴ٸ�
		//���丮��Ʈ�� ��� �����Ǵ��� �߰�
		if (count > 0)
			answer.push_back(count);
	}
	return answer;
}

int main()
{
	vector<int> progresses = { 93, 30, 55 };
	vector<int> speeds = { 1, 30, 5 };
	vector<int> result = solution(progresses, speeds);
	for (auto t : result)
	{
		cout << t << endl;
	}
	return 0;
}