#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
	//����Ƚ��
	int answer = 0;
	//�켱����ť �ƽ���
	priority_queue<int> pq;
	//���糯�� K�� ���� ���������� �ݺ�
	for (int day = 0, j = 0; day < k; day++)
	{
		//���� ������ ���� �ְ� �׳��� �̹� �����ٸ�
		if (dates.size() > j && dates.at(j) <= day)
		{
			//�켱���� ť�� ����
			pq.push(supplies.at(j));
			j++;
		}
		//���� �а��縦 �ٛ��ٸ�
		if (stock == 0)
		{
			//���� �������ִ� �ִ뷮�� ���޹���
			stock += pq.top();
			//�켱���� ť���� ����
			pq.pop();
			//���޹��� Ƚ������
			answer++;
		}
		//�а��� ���
		stock--;
	}

	return answer;
}


int main()
{
	vector<int> dates = { 4,10,15 };
	vector<int> supplies = { 20,5,10 };
	int k = 30;
	int stock = 4;
	cout << solution(stock, dates, supplies, k);
	return 0;
}