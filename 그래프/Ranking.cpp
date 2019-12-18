#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
	//�¸��� ��� �߰�
	for (auto r : results) 	graph[r[0]][r[1]] = true;
	//�ڽ����� �� ����� �¸��Ѱ��� �ڽŵ� �¸��� ó���ϱ�
	//i ���İ��� ���
	for (size_t i = 1; i <= n; i++) {
		//j ��߳��
		for (size_t j = 1; j <= n; j++) {
			//k �������
			for (size_t k = 1; k <= n; k++) {
				if (graph[i][j] && graph[j][k]) {
					graph[i][k] = true;
				}
			}
		}
	}
	for (size_t i = 1; i <= n; i++) {
		int count = 0;
		//���� �̰�ų� ������ �̱��� �Ǵ��� �����ϹǷ� count����
		for (size_t j = 1; j <= n; j++) {
			if (graph[i][j] || graph[j][i])	count++;
		}
		//�Ǵ��� �������Ǽ��� ���ο�-1�̶�� Ȯ���� �����ϹǷ� answer����
		if (count == n - 1)	answer++;
	}
	return answer;
}

void print(int n, vector<vector<int>> results, int answer) {
	int t = solution(n, results);
	if (t == answer)		cout << "����" << endl;
	else		cout << "Ʋ��" << endl;
}

int main() {
	print(5, { {4, 3}, {4, 2}, {3, 2}, {1, 2},{2, 5} }, 2);
	return 0;
}