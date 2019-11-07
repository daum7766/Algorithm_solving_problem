#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
	DFS ���
*/

void dfs(vector<int>& numbers, int& answer, int target, int count = 0, int sum = 0){
	int s = sum, c = count;
	//���������� ��ȸ�ߴٸ�
	if (c == numbers.size() - 1) {
		//���ݱ��� ���Ѱ��� ������ ���Ҹ� ���Ҷ� Ÿ�ٰ� ���ٸ� ī��Ʈ ����
		if (target == s + numbers[c])
			answer++;
		//���ݱ��� ���Ѱ��� ������ ���Ҹ� ���� Ÿ�ٰ� ���ٸ� ī��Ʈ ����
		if (target == s - numbers[c])
			answer++;
		return;
	}
	//�ִ���̱��� �����ʾҴٸ� ���ϰų� �����·� Ž��
	dfs(numbers, answer, target, count + 1, s + numbers[c]);
	dfs(numbers, answer, target, count + 1, s - numbers[c]);
}


int solution(vector<int> numbers, int target) {
	int answer = 0;
	dfs(numbers, answer, target);
	return answer;
}

void print(vector<int> numbers, int target, int answer)
{
	int t = solution(numbers, target);
	cout << t << " , ";
	if (t == answer)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}

int main() {

	print({ 1,1,1,1,1 }, 3, 5);

	return 0;
}