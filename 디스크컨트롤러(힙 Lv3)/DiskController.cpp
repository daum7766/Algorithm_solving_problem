#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
	return a.at(0) < b.at(0);
}

struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		return a.at(1) > b.at(1);
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;	//��� ����� ����
	int j = 0;	//�ε��� ������
	int time = 0;	//�ð� üũ��
	sort(jobs.begin(), jobs.end(), compare);
	priority_queue<vector<int>, vector<vector<int>>, cmp> pq; //�켱���� ť min heap
	//��⿭�� ���� �켱���� ť�� �������� �ݺ�
	while (j < jobs.size() || !pq.empty()) {
		//���� ��⿭�� �����ְ�, ���� ��⿭�� ����ð����� �۴ٸ�
		if (jobs.size() > j && time >= jobs.at(j).at(0)) {
			//�켱���� ť�� �߰�
			pq.push(jobs.at(j));
			//�ε��� ����
			j++;
			//�����ð��뿡 �ٸ��۾��� �������� �� �����Ƿ� �ٽ� Ȯ��
			continue;
		}
		//ť�� ������� �ʴٸ�
		if (!pq.empty()) {
			//�ð��� ���۾��� ���������� �ɸ��� �ð���ŭ �߰�
			time += pq.top().at(1);
			//�۾��ð��� ��� �ð���ŭ �߰�(����ð� - ���� �ð�)
			answer += time - pq.top().at(0);
			//�۾��� �������Ƿ� �켱���� ť���� ����
			pq.pop();
		}
		else {//ť�� ����ִٸ�
			time++;//�ð�����
		}
	}
	return answer / jobs.size();//����� ���ؾ��ϹǷ� ���۾��� ������ ������
}

int main()
{
	//int ajobs[][2] = { {0, 3}, {1, 9}, {2, 6}};
	int ajobs[][2] = { {1, 4}, {1, 3}, {1, 5}, {2, 4}, {2, 3} ,{3, 1} };
	vector<vector<int>> jobs;
	for (int i = 0; i < 6; i++)
	{
		vector<int> temp;
		temp.push_back(ajobs[i][0]);
		temp.push_back(ajobs[i][1]);
		jobs.push_back(temp);
	}
	cout << solution(jobs) << endl;
	return 0;
}