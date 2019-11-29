#include <string>
#include <stack>
#include <iostream>
using namespace std;

int solution(string s) {
	stack<char> str;
	//ó������ ������ ��ȸ
	for (int i = 0; i < s.length(); i++) {
		//������ ����ְų� ž�ϰ� ������ڰ� �ٸ��ٸ� ���ÿ� Ǫ��
		if (str.empty() || str.top() != s[i])	str.push(s[i]);
		//ž�� ������ڰ� ���ٸ� ž���ִ� ��������
		else if (str.top() == s[i])		str.pop();
	}
	//������ ����ִٸ� ��������Ѱ��̹Ƿ� 1����
	if (str.empty())	return 1;
	return 0;
}

void print(string s, int answer) {
	int t = solution(s);
	if (t == answer)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}

int main() {
	print("baabaa", 1);
	print("cdcd", 0);
	return 0;
}