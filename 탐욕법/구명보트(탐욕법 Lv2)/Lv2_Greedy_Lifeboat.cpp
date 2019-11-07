#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;


int solution(vector<int> people, int limit) {
	int answer = 0, cnt = 0;
	//�ڿ��� �տ��� ����Ű�� �ε���
	int begin = 0, end = 1;
	//�����ϱ�
	sort(people.begin(), people.end());
	while (true) {
		//���� �ڿ����Ը� �ֱ�
		int first = people[people.size() - end++];
		cnt++;	//�Ѹ� ���ٰ� ǥ��
		//�ִ����ѿ� ���Ϲ��ſ����� ��������� ���� ���������� Ż���ִٸ�
		if (limit - first >= people[begin])
		{
			//�ջ�� �ε��� ������ ��Ʈ�� ź��� �߰�
			begin++;
			cnt++;
		}
		//��Ʈ ����Ƚ�� ����
		answer++;
		//��Ʈ�� Ÿ�� ��������� ���ο����� ���ų� �������� �ݺ��� ����
		if (cnt >= people.size())
			break;
	}
	return answer;
}


void print(vector<int> people, int limit, int answer)
{
	int t = solution(people, limit);
	cout << t << " ";
	if (t == answer)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;

}


int main() {

	print({ 70, 50, 80, 50 }, 100, 3);
	print({ 70, 80, 50 }, 100, 3);

	return 0;
}