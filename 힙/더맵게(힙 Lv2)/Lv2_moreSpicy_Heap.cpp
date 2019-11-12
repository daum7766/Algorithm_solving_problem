#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	//�켱����ť ��������
	priority_queue<int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());
	//������ �ּ�2���̻��̰� ���Ͼȸſ� ������ K���� ������������ �ݺ�
	while (pq.size() > 1 && pq.top() < K){
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
	if (pq.top() < K)	return -1;
	return answer;
}

void print(vector<int> scoville, int K, int answer) {
	int t = solution(scoville, K);
	if (t == answer)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;

}

int main(){
	
	print({ 1,2,3,9,10,12 }, 4, 2);
	return 0;
}