#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void bfs(int current, vector<vector<bool>>& graph, vector<int>& distance, vector<int> queue) {
	//�ӽ�ť
	vector<int> m_queue;
	//���ڰ����� �Ѿ�� ť�� �������� �ݺ�
	while (!queue.empty()) {
		//����Ǿ��ִ� �׷����� Ȯ���Ѵ�.
		for (size_t i = 1; i < graph.size(); i++) {
			//ť�� ����ִ� ���� ������ �Ǿ��־���ϰ�, �Ÿ������� �ȵ��־���Ѵ�.
			if (graph[queue[0]][i] && !distance[i]) {
				//�ӽ�ť�� �ְ� �Ÿ��� �־��ش�.
				m_queue.push_back(i);
				distance[i] = current;
			}
		}
		//ť���ִ� ������ pop
		queue.erase(queue.begin());
	}
	//�ӽ�ť�� ������� �ʴٸ� bfs ���
	if (!m_queue.empty())	bfs(current + 1, graph, distance, m_queue);
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	//����� ����ŭ 2�������͸� ����� 1�������ʹ� false�� �����Ѵ�.
	vector<vector<bool>> graph(n, vector<bool>(n, false));
	//�Ÿ��� n���� 1�������ͷ� 0���� �ʱ�ȭ
	vector<int> distance(n, 0);
	//����Ǿ� �ִ� �������� true�� ����
	for (auto e : edge) {
		graph[e[0] - 1][e[1] - 1] = true;
		graph[e[1] - 1][e[0] - 1] = true;
	}
	//bfs�Լ� ����, ù���� 0���� �����Ѵ�.
	bfs(1, graph, distance, { 0 });
	//�ִ�Ÿ��� ���ؼ� �ִ�Ÿ��� ��������ŭ answer������ ����
	int max = *max_element(distance.begin(), distance.end());
	for (auto d : distance) {
		if (d == max)	answer++;
	}
	return answer;
}

void print(int n, vector<vector<int>> edge, int answer) {
	int t = solution(n, edge);
	if (t == answer)		cout << "����" << endl;
	else		cout << "Ʋ��" << endl;
}

int main() {
	print(6, { {3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2} }, 3);
	return 0;
}