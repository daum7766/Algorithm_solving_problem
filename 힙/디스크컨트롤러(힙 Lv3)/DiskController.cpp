#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		return a.at(1) > b.at(1);
	}
};

int solution(vector<vector<int>> jobs) {
	//��� ����� ����, �ε��� ������, �ð�üũ��
	int answer = 0, j = 0, time = 0;
	//�ð��� ���� ������������ ����
	sort(jobs.begin(), jobs.end());
	priority_queue<vector<int>, vector<vector<int>>, cmp> pq; //�켱���� ť min heap
	//��⿭�� ���� �켱���� ť�� �������� �ݺ�
	while (j < jobs.size() || !pq.empty()) {
		//���� ��⿭�� �����ְ�, ���� ��⿭�� ����ð����� �۴ٸ�
		if (jobs.size() > j && time >= jobs[j][0]) {
			//�켱���� ť�� �߰��ϰ� �ε��� ����
			pq.push(jobs[j++]);
			//�����ð��뿡 �ٸ��۾��� �������� �� �����Ƿ� �ٽ� Ȯ��
			continue;
		}
		//ť�� ������� �ʴٸ�
		if (!pq.empty()) {
			//�ð��� ���۾��� ���������� �ɸ��� �ð���ŭ �߰�
			time += pq.top()[1];
			//�۾��ð��� ��� �ð���ŭ �߰�(����ð� - ���� �ð�)
			answer += time - pq.top()[0];
			//�۾��� �������Ƿ� �켱���� ť���� ����
			pq.pop();
		}
		else //ť�� ����ִٸ� ���� �۾��ð����� �ѱ�
			time = jobs[j][0];
	}
	return answer / jobs.size();//����� ���ؾ��ϹǷ� ���۾��� ������ ������
}

void print(vector<vector<int>> jobs, int answer) {
	int t = solution(jobs);
	if (t == answer)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}

int main() {
	print({ {0, 3}, {1, 9}, {2, 6} }, 9);
	print({ {0, 9}, {0, 4}, {0, 5}, {0, 7}, {0, 3} }, 13);
	print({ {1, 9}, {1, 4}, {1, 5}, {1, 7}, {1, 3} }, 13);
	print({ {0, 3}, {4, 4}, {5, 3}, {4, 1} }, 3);
	print({ {0, 3}, {1, 9}, {500, 6} }, 6);
	return 0;
}