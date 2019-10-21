#include <vector>
#include <iostream>
#include <string>

using namespace std;

int solution(string name) {
	int answer = 0;
	//���̽�ƽ���� �ٲٰ��ִ� ȭ��
	vector<char> names(name.length(), 'A');
	//�ٲ��� �ϴ� ���
	vector<char> temp;
	//temp�� name�� ��� ����ֱ�
	for (int i = 0; i < name.length(); i++)
		temp.push_back(name[i]);
	int i = 0;
	while (true) {
		//���� ���� ����� ���� �ʴ´ٸ�
		if (names.at(i) != temp.at(i)) {
			//�ٲٰ� �ִ� ȭ�鿡 �ݿ��ϰ�
			names.at(i) = temp.at(i);
			int a, b;
			//������ �مf���� Ƚ��
			a = temp.at(i) - 'A';
			//�ڷ� �مf���� Ƚ��
			b = 'Z' + 1 - temp.at(i);
			//���߿� �����ɷ� ����� �߰��ϱ�
			a > b ? answer += b : answer += a;
		}
		int left = 1, right = 1;
		bool check = true;
		//�������� ���� ���������� ���� ����ϱ� 
		while (true) {
			//�ε����� �����ʰ� ������ ���
			int t = (i + right) % names.size();
			//���������� �̵��ϴ� ��ġ�� ����� ���ٸ� ������ ��ĭ��
			if (names.at(t) == temp.at(t))
				right++;
			else//���������� �̵��ؼ� �ٲ�� �Ѵٸ� ����
				break;
			//��� ���ڰ� �Ȱ��Ƽ� right�� ��� �ö󰡸� �ݺ��� Ż��
			if (right > name.size()) {
				check = false;
				break;
			}
		}
		//��繮�ڰ� ������������ ����
		if (check) {
			while (true) {
				//�������� �̵�
				int t = i - left;
				//����� �ε����� 0���� �۴ٸ� �����ֱ�
				if (t < 0)	t = names.size() + t;
				//�������� �̵��ϴ� ��ġ�� ����� �Ȱ��ٸ� ������ ���̵�
				if ((names.at(t) == temp.at(t)))
					left++;
				//���ڰ� �ٸ��� ����
				else
					break;
			}
		}
		else//��� ���ڰ� ������ ��� ���������̹Ƿ� �ݺ��� Ż��
			break;
		//���������� �̵��ϴ°� �̵��̶��
		if (right <= left) {
			//���������� �̵��ؾ� �ϴ¸�ŭ �̵��ϰ�
			i = (i + right) % names.size();
			//�̵��� Ƚ����ŭ ����� �ݿ�
			answer += right;
		}
		else {//�������� �̵��ϴ°� �̵��̶��
			//�������� �̵��ؾ� �ϴ¸�ŭ �̵��ϰ�
			i -= left;
			//�ε����� �Ѿ���� Ȯ���ϰ� �Ѿ�� �ε��� ����
			if (i < 0)
				i += names.size();
			//�̵��� Ƚ����ŭ ����� �ݿ�
			answer += left;
		}
	}
	return answer;
}


void print(string name, int answer)
{
	int a = solution(name);
	cout << a << " ";
	if (answer == a)
		cout << "����" << endl;
	else
		cout << "Ʋ�� " << endl;

}


int main() {

	print("JEROEN", 56);
	print("JAN", 23);
	print("AABAAAAAAAB", 6);
	print("AAAAAAAA", 0);
	print("ABBBBAAAABAA", 14);
	print("ABAAAAAAABA", 6);
	print("AAB", 2);
	print("AABAAAAAAABBB", 12);
	print("ZZZ", 5);

	return 0;
}