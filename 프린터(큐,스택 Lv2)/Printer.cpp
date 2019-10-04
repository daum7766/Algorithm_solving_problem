#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	int count = 0;

	//�Ϲ�ť
	queue<pair<int, int>> que;
	//�켱���� ť
	priority_queue <int> prio_que;

	for (int i = 0; i < priorities.size(); i++) {
		//ť�� ���� ������ �߿䵵�� ����
		que.push(make_pair(i, priorities[i]));
		//�켱��ť�� ����
		prio_que.push(priorities[i]);
	}
	//ť�� �������� �ݺ�
	while (!que.empty()) {
		int index = que.front().first;
		int value = que.front().second;
		que.pop();
		//�켱���� 1������ ���簪�� ���ٸ�
		if (prio_que.top() == value) {
			//�켱����ť pop
			prio_que.pop();
			//�ϳ��� �������Ƿ� count
			count++;
			//���� �������� ���ϴ°Ͱ� ���ٸ�
			if (index == location) {
				//���� ī���͸� ����
				answer = count;
				break;
			}
		}
		//�켱���� 1������ ���簪�� �����ʴٸ� ť �ڿ� �ֱ�
		else {
			que.push(make_pair(index, value));
		}
	}
	return answer;
}


int main()
{
	vector<int> t = { 1, 1, 1, 9, 1, 1, 1 };
	solution(t, 5);

	return 0;
}