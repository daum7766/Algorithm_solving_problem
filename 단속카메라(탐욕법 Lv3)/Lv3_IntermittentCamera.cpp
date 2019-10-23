#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	//�⺻ ī�޶� 1��
	int answer = 1;
	//���� ����Ʈ ����
	sort(routes.begin(), routes.end());
	//�񱳸� ���� ó������ ������ �κ� üũ
	int temp = routes.at(0).at(1);
	//����Ʈ ��ȸ�ϱ�
	for (auto a : routes) {
		cout << a.at(0) << " , " << a.at(1) << endl;
		//���� ���� ������ �κк��� �ڿ� ���� ���´ٸ�
		if (temp < a.at(0)) {
			//ī�޶� ��ġ
			answer++;
			//������ �κ� ����
			temp = a.at(1);
		}
		//���� ������ ������ ���������� 
		if (temp >= a.at(1))
			temp = a.at(1);// ������ �κ��� ������ ����
	}
	return answer;
}

void print(vector<vector<int>> routes, int answer)
{
	int t = solution(routes);
	cout << t << " , ";
	if (t == answer)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;

}


int main()
{
	print({ {-20,15}, {-14, -5}, {-18, -13}, {-5, -3} }, 2);
	print({ {-2, -1}, {1, 2}, {-3, 0} }, 2);
	print({ {0, 0} }, 1);
	print({ {0, 1}, {0, 1}, {1, 2} }, 1);
	print({ {0, 1}, {2, 3}, {4, 5}, {6, 7} }, 4);
	print({ {-20, 15}, {-14, -5}, {-18, -13}, {-5, -3} }, 2);
	print({ {-20, 15}, {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} }, 2);

	return 0;
}