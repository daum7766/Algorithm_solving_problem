#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n) {
	string answer = "";
	string temp[3]{ "4", "1", "2" };
	//n�� 0�� �ɶ����� �ݺ�
	while (n) {
		//1,2,4 4���� ���ڸ� ����ϹǷ� 3 ������ ����
		//0�ϰ�� 4�� ��ü
		answer = temp[n % 3] + answer;
		//�������� 0�ϰ�� -1�� ����� ���� �����, �ƴϸ� 3�ϰ�� 14�� ����
		if (!(n % 3))
			n = n / 3 - 1;
		else
			n = n / 3;
	}
	return answer;
}


void print(int N, string answer) {
	string t = solution(N);
	cout << t << " , ";
	if (answer == t)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}

int main() {

	print(1, "1");
	print(2, "2");
	print(3, "4");
	print(4, "11");
	print(5, "12");
	print(6, "14");
	print(7, "21");
	print(8, "22");
	print(9, "24");
	print(10, "41");
	return 0;
}