#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<int> solution(vector<int> prices) {
	vector<int> answer;
	//�������� �����ϰ� ��ȸ(�������� ���ݺ����� ���⶧��)
	for (int i = 0; i < prices.size() - 1; i++) {
		int count = 0;
		//�ڱ⺸�� �ڿ��� ��ȸ�ϸ鼭 �ڱ⺸�� ������ ������ �ݺ����� ����
		for (int j = i + 1; j < prices.size(); j++) {
			count++;
			if (prices.at(i) > prices.at(j))
				break;
		}
		//���ӵ� �ð��Է�
		answer.push_back(count);
	}
	//���� �������� ó��
	answer.push_back(0);

	return answer;
}

void print(vector<int> prices, vector<int> answer) {
	vector<int> t = solution(prices);
	//cout << t << " , ";
	if (answer == t)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}

int main() {
	print({ 1,2,3,2,3 }, { 4,3,1,1,0 });
	return 0;
}
