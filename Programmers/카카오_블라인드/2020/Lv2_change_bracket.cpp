#include <iostream>
#include <string>

using namespace std;
//�ùٸ� ���ڿ����� Ȯ��
bool check(string p) {
	int t{};
	for (size_t i = 0; i < p.length(); i++) {
		if (p[i] == '(')       t++;
		else {
			//��ȣ�� ���� ����
			if (!t)     return false;
			t--;
		}
	}
	return true;
}

string recursion(string p) {
	//������� ���ִٸ� ���ִ°� ����
	if (p == "")	return p;
	string u{}, v{};
	int Lcount{}, Rcount{};
	for (size_t i = 0; i < p.length(); i++) {
		if (p[i] == '(')     Lcount++;
		else        Rcount++;
		//�������� ���ڿ��� �Ǿ��ٸ� �и�
		if (Lcount == Rcount) {
			u = p.substr(0, i + 1);
			v = p.substr(i + 1);
			break;
		}
	}
	//u�� �ùٸ� ���ڿ��̸� vó���� u�� �ٿ��� ��ȯ
	if (check(u)) 	return u + recursion(v);
	//u�� �ùٸ� ���ڿ��� �ƴ϶��
	else {
		//�� ���ڿ��� "("�� ���δ�
		string temp{ "(" };
		//v�� ��ͼ����� ")"�� ���δ�
		temp += recursion(v) + ")";
		//u��  ���Ͼհ� ������ ���ڸ� ����
		u = u.substr(1, u.length() - 2);
		//���ڿ� ��ȣ ����
		for (size_t i = 0; i < u.length(); i++) {
			if (u[i] == '(')	temp += ')';
			else	temp += '(';
		}
		return temp;
	}
}

string solution(string p) {
	//ó���˻������� �¾Ҵٸ�
	if (check(p))     return p;
	return recursion(p);
}

void print(string p, string answer) {
	string t = solution(p);
	if (t == answer)	cout << "����" << endl;
	else	cout << "����" << endl;
}

int main() {
	print(")()()()(", "(((())))");
	print("(()())()", "(()())()");
	print(")(", "()");
	print("()))((()", "()(())()");
	return 0;
}