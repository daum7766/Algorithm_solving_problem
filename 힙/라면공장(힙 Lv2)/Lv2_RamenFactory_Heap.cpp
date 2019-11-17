#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k){
	//����Ƚ��
	int answer = 0;
	//�켱����ť �ƽ���
	priority_queue<int> pq;
	//���糯�� K�� ���� ���������� �ݺ�
	for (int day = 0, j = 0; day < k; day++){
		//���� ������ ���� �ְ� �׳��� �̹� �����ٸ�
		if (dates.size() > j && dates.at(j) <= day){
			//�켱���� ť�� ����
			pq.push(supplies.at(j));
			j++;
		}
		//���� �а��縦 �ٛ��ٸ�
		if (!stock){
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

void print(int stock, vector<int> dates, vector<int> supplies, int k, int answer) {
	int t = solution(stock, dates, supplies, k);
	if (t == answer)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}


int main(){
	print(4, { 4, 10, 15 }, {20, 5, 10}, 30, 2);
	return 0;
}