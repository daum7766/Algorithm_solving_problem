#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
//set�� �̿��� Ǯ��
vector<int> solution(vector<string> operations) {
	multiset<int> mset;
	for (auto o : operations) {
		string a = o.substr(0, 1);//���� ���� Ȯ��
		int num = atoi(o.substr(2).c_str());//���� ���� Ȯ��
		//�չ��ڰ� I(�빮�� i) ��� ������ �ֱ�
		if (a == "I") {
			mset.insert(num);
		}
		//I�� �ƴϰ� ���� ������� �ʴٸ� �ִ� Ȥ�� �ּڰ� ����
		else if (!mset.empty()) {
			if (num == 1)
				mset.erase(--mset.end());
			else
				mset.erase(mset.begin());
		}
	}
	//��Ƽ���� ����ִٸ� 0,0 ��ȯ
	if (mset.empty())
		return { 0 , 0 };
	else		//������� �ʴٸ� �ִ� �ּڰ� ��ȯ
		return { *--mset.end() , *mset.begin() };
}
//deque�� �̿��� Ǯ��
vector<int> solution2(vector<string> operations) {
	vector<int> answer;
	deque<int> deq;//������ ������ �������
	for (auto o : operations)
	{
		string a = o.substr(0, 1);//���� ���� Ȯ��
		int num = atoi(o.substr(2).c_str());//���� ���� Ȯ��
		//�չ��ڰ� I(�빮�� i) ���
		if (a == "I") {
			//������ �ֱ�
			deq.push_back(num);
		}
		//I�� �ƴϰ� ���� ������� �ʴٸ�
		else if (!deq.empty())
		{
			//���� �ѹ��ϱ�
			sort(deq.begin(), deq.end());
			if (num == 1)
				deq.pop_back();			//�������� �����̹Ƿ� �ڿ����� ����
			else
				deq.pop_front();		//�ּҰ��� �����ϹǷ� �տ��� ����
		}
	}
	if (deq.empty())
	{
		//ť�� ����ִٸ� 0,0 �ֱ�
		answer.push_back(0);
		answer.push_back(0);
	}
	else
	{
		//ť�� ������� �ʴٸ� ������ ���ֱ�
		sort(deq.begin(), deq.end());
		answer.push_back(deq.back());
		answer.push_back(deq.front());
	}

	return answer;
}

int main()
{
	//vector<string> oper = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
	vector<string> oper = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };
	vector<int> result = solution(oper);
	for (auto r : result)
	{
		cout << r << endl;
	}
	return 0;
}
