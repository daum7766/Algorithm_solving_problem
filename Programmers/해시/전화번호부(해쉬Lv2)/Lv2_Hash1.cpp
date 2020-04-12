#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//hash ������
//hash �����ε� ����� ���ϴٴ�...
bool solution(vector<string> phone_book) {
	bool answer = true;
	//���ϱ� ���� ����
	sort(phone_book.begin(), phone_book.end());
	//ó������ ������ ��ȸ
	for (int i = 0; i < phone_book.size() - 1; i++){
		//i���� �޺κи� ��ȸ
		for (int j = i + 1; j < phone_book.size(); j++){
			//������ �Ǿ��ֱ⶧���� ���̺� ��������
			//���ϴ� �κ��� ��ġ�Ѵٸ� false ����
			if (phone_book[i] == phone_book[j].substr(0, phone_book[i].length()))
				return false;
		}
	}
	return answer;
}


int main()
{
	string a[] = { "119", "97674223", "1195524421" };
	vector<string> b;
	for (int i = 0; i < 3; i++)
	{
		b.push_back(a[i]);
	}
	cout << solution(b) << endl;
	return 0;
}