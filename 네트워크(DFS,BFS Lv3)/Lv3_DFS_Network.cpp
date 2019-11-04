#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool dfs(vector<vector<int>>& computers, int n) {
	//�̹� ��ȸ�� ����� ����(����Լ� Ż������)
	if (!computers[n][n])
		return false;
	//��ȸ�ߴٰ� �����ϱ�
	computers[n][n] = 0;
	//������ŭ �ݺ�
	for (int i = 0; i < computers.size(); i++) {
		//����� ��尡 �ִٸ� ���
		if (computers[n][i])
			dfs(computers, i);
	}
	return true;
}


int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		//��ȸ���� ���� ����� dfsŽ���� answer����
		if (computers[i][i] && dfs(computers, i))
			answer++;
	}
	return answer;
}

void print(int n, vector<vector<int>> computers, int answer)
{
	int t = solution(n, computers);
	cout << t << " , ";
	if (t == answer)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}

int main() {

	print(3, { {1,1,0}, {1,1,0},{0,0,1} }, 2);
	print(3, { {1,1,0}, {1,1,1},{0,1,1} }, 1);

	return 0;
}