#include <iostream>
#include <string>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	//�ʿ��� ���ڼ���ŭ �ݺ��ϱ�
	for (int j = 0, index = -1; j < number.length() - k; j++) {
		char max = 0;
		//�տ��� ���ܾ� �Ǵ� ���� �߿� ���� ū�� üũ
		for (int i = index + 1; i <= k + j; i++) {
			if (max < number[i]) {
				index = i;
				max = number[i];
			}
		}
		//���� ū���� ���信 �߰�
		answer += max;
	}
	return answer;
}

void print(string number, int k, string answer) {
	string t = solution(number, k);
	if (t == answer)	cout << "����" << endl;
	else	cout << "Ʋ��" << endl;
}

int main() {
	print("1924", 2, "94");
	print("1231234", 3, "3234");
	print("4177252841", 4, "775841");
	print("9999", 2, "99");
	return 0;
}