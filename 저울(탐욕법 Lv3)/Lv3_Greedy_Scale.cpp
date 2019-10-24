#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
	//1���� �񱳸� ����
	int answer = 1;
	sort(weight.begin(), weight.end());
	/*
	ex) ���Ͱ� {3, 1, 6, 2, 7, 30, 1}�̶�� ����
	������ {1, 1, 2, 3, 6, 7, 30}�� �ȴ�.
	�̰� �������� ������ �պ��� ���� ���� �񱳸� ����
	���� �ؾ� ������ answer-1�� ���� �߷� ����� �ִ� �ִ��� ���̴�.
	1,1,2,3�� �߸� �̿��ϸ� 7���� ��� ����� ���� ���� �� �ִ�.
	4 = 2 + 1 +1
	5 = 2 + 3
	6 = 3 + 2 + 1
	7 = 3 + 2 + 1 + 1
	���� ���ݱ��� ���Ѽ����� �� ū �߰� ���´ٸ� answer�� ���� �� ���� ���̴�.
	*/
	for (auto w : weight) {
		if (answer < w)
			break;
		answer += w;
	}
	return answer;
}

void print(vector<int> weight, int answer)
{
	int t = solution(weight);
	cout << t << " , ";
	if (answer == t)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}

int main()
{
	print({ 3,1,6,2,7,30,1 }, 21);
	return 0;
}