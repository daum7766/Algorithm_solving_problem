#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	//�켱����ť ��������
	priority_queue<int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());
	//������ �ּ�2���̻��̰� ���Ͼȸſ� ������ K���� ������������ �ݺ�
	while (pq.size() > 1 && pq.top() < K)
	{
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		//�ΰ��� ������ ��� �켱���� ť�� �߰�
		pq.push(first + (second * 2));
		//���� Ƚ�� ����
		answer++;
	}
	//��� ������ �������� �켱���� ť�� ���� ���� ���� ������ K���� �۴ٸ� -1�� ����
	if (pq.top() < K)
	{
		return -1;
	}
	return answer;
}

int main()
{
	vector<int> scovile = { 1,2,3,9,10,12 };
	int k = 7;
	cout << solution(scovile, k) << endl;
	return 0;
}