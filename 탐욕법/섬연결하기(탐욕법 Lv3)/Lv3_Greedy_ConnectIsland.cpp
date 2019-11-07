#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//����� �˰��� : ũ�罺Į �˰���
//���뼺�� ���� �� ��尳���� ã�Ƽ� ���Ϳ� �Ҵ�

//����ġ�� ���� �������� ������ ���� ��
bool cmp(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

//�θ���ã��
int getParent(vector<int>& parent, int x) {
	//�θ��尡 �ڽ��̶�� �ڽ��� ����
	if (parent.at(x) == x)
		return x;
	//�θ��尡 �ڽ��� �ƴ϶�� �ֻ��� �θ��� ã��
	return parent.at(x) = getParent(parent, parent.at(x));
}

//�θ��� �����ϱ�
void unionParent(vector<int>& parent, int a, int b) {
	//�ΰ��� �θ� �����ͼ�
	a = getParent(parent, a);
	b = getParent(parent, b);
	//���� ������� �θ�� ���ս�Ű��
	a < b ? parent.at(b) = a : parent.at(a) = b;
}

//�θ��尡 ������ ��
bool find(vector<int>& parent, int a, int b) {
	//�θ��带 �����ͼ�
	a = getParent(parent, a);
	b = getParent(parent, b);
	//�񱳳��� ����, ����Ŭ ������
	return a == b;
}


int solution(int n, vector<vector<int>> costs) {
	int answer = 0, max = 0;
	//����ġ �������� ����
	sort(costs.begin(), costs.end(), cmp);
	//costs�� ��ȸ�ؼ� ���� ���� ���ã��
	for (auto a : costs)
		if (max < a.at(1))
			max = a.at(1);
	//�θ���� ����Ʈ ����
	vector<int> parent;
	//�θ���� ����Ʈ �ʱ�ȭ
	for (int i = 0; i <= max; i++)
		parent.push_back(i);
	//�ڽ�Ʈ�� ó������ ��ȸ
	for (auto a : costs) {
		//�ΰ��� �θ��尡 �����ʴٸ�->����Ŭ�� ���� �ȵȴٸ�
		if (!find(parent, a.at(0), a.at(1))) {
			//����� ����ġ �߰�
			answer += a.at(2);
			//�θ��� �����ϱ�
			unionParent(parent, a.at(0), a.at(1));
		}
	}
	return answer;
}

void print(int n, vector<vector<int>> costs, int answer)
{
	int t = solution(n, costs);
	cout << t << " , ";
	if (t == answer)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;

}


int main()
{
	print(4, { {0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8} }, 4);
	return 0;
}