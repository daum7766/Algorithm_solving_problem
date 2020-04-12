#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int solution(string arrangement) {
	int answer = 0;
	stack<int> num;
	//������ ó������ ���������� ��ȸ
	for (int i = 0; i < arrangement.length(); i++){
		//���� ��ȣ��� ���ÿ� �߰�
		if (arrangement[i] == '(')
			num.push(1);
		else{
			//�ݴ� ��ȣ��� ���ÿ��� �ϳ�����
			num.pop();
			//�� ��ȣ�� ���� ��ȣ���ٸ� �������̹Ƿ� ������ȣ��ŭ �����߰�
			if (arrangement[i - 1] == '(')
				answer += num.size();
			else//�� ��ȣ�� ���� ��ȣ�� �ƴϾ��ٸ� �踷����� �������̹Ƿ� 1�� �߰�
				answer++;
		}
	}
	return answer;
}

void print(string a, int answer) {
	int t = solution(a);
	cout << t << ", ";
	if (a == answer)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}

int main(){
	print("()(((()())(())()))(())", 17);
	return 0;
}