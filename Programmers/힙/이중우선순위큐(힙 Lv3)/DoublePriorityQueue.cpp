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
		if (a == "I") 	mset.insert(num);
		//I�� �ƴϰ� tpt�� ������� �ʴٸ� �ִ� Ȥ�� �ּڰ� ����
		else if (!mset.empty()) {
			if (num == 1)	mset.erase(--mset.end());
			else	mset.erase(mset.begin());
		}
	}
	//��Ƽ���� ����ִٸ� 0,0 ��ȯ
	if (mset.empty())	return { 0 , 0 };
	//������� �ʴٸ� �ִ� �ּڰ� ��ȯ
	else	return { *--mset.end() , *mset.begin() };
}

//deque�� �̿��� Ǯ��
vector<int> solution2(vector<string> operations) {
	deque<int> deq;
	for (auto o : operations){
		string a = o.substr(0, 1);//���� ���� Ȯ��
		int num = atoi(o.substr(2).c_str());//���� ���� Ȯ��
		//�չ��ڰ� I(�빮�� i) ��� ������ �ֱ�
		if (a == "I") 	deq.push_back(num);
		//I�� �ƴϰ� ���� ������� �ʴٸ�
		else if (!deq.empty()){
			//���� �ѹ��ϱ�-> �ڵ����� ������ �ȵǱ⶧��
			sort(deq.begin(), deq.end());
			if (num == 1)	deq.pop_back();			//�������� �����̹Ƿ� �ڿ����� ����
			else	deq.pop_front();		//�ּҰ��� �����ϹǷ� �տ��� ����
		}
	}
	if (deq.empty())	return { 0,0 };
	//���� ������� �ʴٸ� ������ ���ֱ�
	sort(deq.begin(), deq.end());
	return { deq.back(), deq.front() };
}

void print(vector<string> operations, vector<int> answer) {
	vector<int> t = solution(operations);
	if (t == answer)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}

int main(){
	print({ "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" }, {0,0});
	print({ "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" }, {333, -45});
	return 0;
}
