#include <string>
#include <iostream>
#include <cmath>

using namespace std;

//���� ���ڿ� Ȯ���Լ�
int nextCheck(string& dartResult, int i) {
	//�ε����� ���̸� �����ʴ��� Ȯ��
	if (i + 1 < dartResult.length()) {
		if (dartResult[i + 1] == '*')	return 2;	//��Ÿ���̶�� 2��
		else if (dartResult[i + 1] == '#') return -1;	//�������̶�� -1��
	}
	return 1;	//�ƹ��͵� �ƴ϶�� 1��
}

int solution(string dartResult) {
	int current = 0, Squared = 0, score[3]{ 0, 0, 0 };
	//���ڿ��� ó������ ������ �ݺ�
	for (int i = 0; i < dartResult.length(); i++) {
		//�� �������� Ȯ��
		if (dartResult[i] == 'S')	Squared = 1;
		else if (dartResult[i] == 'D')	Squared = 2;
		else if (dartResult[i] == 'T')	Squared = 3;
		//������ Ȯ�εǾ��ٸ�
		if (Squared) {
			//���� ���� Ȯ���ϱ� 0~10;
			int temp_int = stoi(dartResult.substr(0, i));
			//�������ڸ� Ȯ���ؼ� 2������ -1������ 1������ Ȯ��
			int mulityply = nextCheck(dartResult, i);
			//1�谡 �ƴ϶�� -> 2�� Ȥ�� -1���� 2ĭ�ڷ� �̵�
			if (mulityply != 1) 	dartResult = dartResult.substr(i + 2);
			//�ɼ��� �����Ƿ� 1ĭ�ڷ� �̵��Ѵ�.
			else	dartResult = dartResult.substr(i + 1);
			//2���������ٸ� �������� ���� 2��� �ٲ��ش�.
			if (mulityply == 2 && current) 	score[current - 1] *= 2;
			//���� ��ƮȽ���� ������ �־��ش�.
			score[current] = pow(temp_int, Squared) * mulityply;
			//���ڿ��� �߶����Ƿ� �ε����ʱ�ȭ, ��Ʈȸ������,  S D T���� �ʱ�ȭ
			i = 0;	Squared = 0;  current++;
		}
	}
	return score[0] + score[1] + score[2];
}


void print(string dartResult, int answer) {
	int t = solution(dartResult);
	if (answer == t)	cout << "����" << endl;
	else	cout << "Ʋ��" << endl;
}

int main() {
	print("1S2D*3T", 37);
	print("1D2S#10S", 9);
	print("1D2S0T", 3);
	print("1S*2T*3S", 23);
	print("1D#2S*3S", 5);
	print("1T2D3D#", -4);
	print("1D2S3T*", 59);

	return 0;
}
