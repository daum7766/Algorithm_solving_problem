#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	//���� ���ο� �ö����ִ� �� ����
	int answer = 0, currentWeight = 0;
	//���ο� �ö����ִ���, ������ ���� �Ÿ�
	queue<int> count, bridgeOn;
	while (true) {
		//�߰��� ���� ���������� ����� �ٲ�⶧���� size����
		int size = bridgeOn.size();
		for (int i = 0; i < size; i++)
		{
			int length = bridgeOn.front();
			bridgeOn.pop();
			//���� �������̰� ���ٸ�
			if (length <= 1) {
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
		if (truck_weights.size() > 0 && currentWeight + truck_weights.at(0) <= weight) {
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
			break;
	}
	return answer;
}

void print(int bridge_length, int weight, vector<int> truck_weights, int answer)
{
	int t = solution(bridge_length, weight, truck_weights);
	cout << t << " , ";
	if (t == answer)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}

int main() {
	print(100, 100, { 10,10,10,10,10,10,10,10,10,10 }, 110);
	print(2, 10, { 7,4,5,6 }, 8);
	print(100, 100, { 10 }, 101);

	return 0;
}