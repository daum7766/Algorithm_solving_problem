#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
	int count = 0;
	//���ڿ� ��ȸ
	for (auto st : s) {
		//��ȣ�� ������ȣ�̸� ī��Ʈ����
		if (st == '(')
			count++;
		//������ȣ�ε� ������ȣ�� 1���̻� �ִٸ� ī��Ʈ ����
		else if (st == ')' && count > 0)
			count--;
		//�̿ܿ��� false ����
		else
			return false;
	}
	//0�϶��� Ʈ�� ����
	return !count;
}

void print(string s, bool answer) {
	bool t = solution(s);
	//cout << t << " , ";
	if (answer == t)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}

int main() {
	print("()()", true);
	print("(())()", true);
	print(")()(", false);
	print("(()(", false);
	return 0;
}
