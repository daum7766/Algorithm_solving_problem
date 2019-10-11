#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	//���ο� �ö����ִ���
	queue<int> count;
	//���� ���ο� �ö����ִ� �� ����
	int currentWeight = 0;
	//������ ���� �Ÿ�
	queue<int> bridgeOn;
	while (true)
	{
		//�߰��� ���� ���������� ����� �ٲ�⶧���� size����
		int size = bridgeOn.size();
		for (int i = 0; i < size; i++)
		{
			int length = bridgeOn.front();
			bridgeOn.pop();
			//���� �������̰� ���ٸ�
			if (length <= 1)
			{
				//���ο��� ������ ���Ը� ����
				currentWeight -= count.front();
				//���ο� �ö��� �ִ��� ����
				count.pop();
				continue;
			}
			//�����ִٸ� ���̰����� �ٽóֱ�
			bridgeOn.push(length - 1);
		}
		//������� 1���̻� �ְ� ���ΰ� ���Ը� �ߵ� �� �ִٸ�
		if (truck_weights.size() > 0 && currentWeight + truck_weights.at(0) <= weight)
		{
			//���ο� �ö����ִ� �� �߰�
			count.push(truck_weights.at(0));
			//���� �ö����ִ� ���� �߰�
			currentWeight += truck_weights.at(0);
			//���� ���ΰŸ� �߰�
			bridgeOn.push(bridge_length);
			//������� ����
			truck_weights.erase(truck_weights.begin());
		}
		//�ð��� ����
		answer++;
		//���ο� �ö����ִ����� ������� ��ξ��ٸ� �ݺ��� Ż��
		if (truck_weights.size() == 0 && count.size() == 0)
		{
			break;
		}
	}
	return answer;
}

int main()
{
	vector<int> a = { 10,10,10,10,10,10,10,10,10,10 };
	cout << solution(100, 100, a) << endl;

	return 0;
}