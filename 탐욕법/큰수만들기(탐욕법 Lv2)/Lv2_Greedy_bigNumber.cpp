#include <vector>
#include <iostream>
#include <string>

using namespace std;


string solution(string number, int k) {
	string answer = "";
	int t = number.length() - k;
	//�ʿ��� ���ڼ���ŭ �ݺ��ϱ�
	for (int j = t; j > 0; j--) {
		int index = 0;
		char max = 0;
		//�տ��� ���ܾ� �Ǵ� ���� �߿� ���� ū�� üũ
		for (int i = 0; i <= number.length() - j; i++) {
			if (max < number[i]) {
				index = i;
				max = number[i];
			}
		}
		//���� ū���� ���信 �߰��ϰ�
		answer += max;
		//���� �����κи�ŭ �����
		number.replace(0, index + 1, " ");
	}
	return answer;
}


void print(string number, int k, string answer)
{
	string t = solution(number, k);
	cout << t << " ";
	if (t == answer)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;

}


int main() {
	print("9999", 2, "99");
	print("1924" , 2, "94");
	print("1231234", 3, "3234");
	print("4177252841", 4, "775841");


	return 0;
}