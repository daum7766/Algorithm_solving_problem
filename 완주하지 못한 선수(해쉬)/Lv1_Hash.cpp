#include <vector>
#include <string>
#include <unordered_map>//�ؽ��� ���
#include <iostream>//���� ��¿�
#include <algorithm>//�ַ�� 2��
using namespace std;

//�ؽ����̺��� �̿��� �ַ��
string solution(vector<string> participant, vector<string> completion)
{
	string answer = "";
	unordered_map<string, int> temp;
	for (string name : participant)
	{
		//�ؽ����̺� key������ name�� �ְ� ���� ����
		temp[name]++;
	}
	for (string name : completion)
	{
		//name key�� �����Ͽ� ���� ����
		temp[name]--;
	}
	//ó������ �ؽ����̺� ��ȸ
	for (auto pair : temp)
	{
		//�ؽ����̺��� 2��°���� 0���� ũ�ٸ�
		if (pair.second > 0)
		{
			//answer�� �ؽ����̺� key���� ����
			answer = pair.first;
			break;
		}
	}
	return answer;
}

//������ �̿��� �ַ��
string solution2(vector<string> participant, vector<string> completion)
{
	//�����ڿ� ������ ����Ʈ�� ����
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	//������ ����Ʈ ��ȸ
	for (int i = 0; i < completion.size(); i++)
	{
		//�����ڰ� ������ �̸��� �ٸ��ٸ�
		if (participant[i] != completion[i])
		{
			//�ٸ� �̸����� ����
			return participant[i];
		}
	}
	//���� ���ǿ� �ɸ��� �ʾҴٸ� �������� ���� �������� ����
	return participant[participant.size() - 1];
}

int main() {
	vector<string> a, b;
	string a1[] = { "marina", "josipa", "nikola", "vinko", "filipa" };
	string a2[] = { "josipa", "filipa", "marina", "nikola" };

	for (int i = 0; i < 5; i++)
	{
		a.push_back(a1[i]);
	}
	for (int i = 0; i < a.size() - 1; i++)
	{
		b.push_back(a2[i]);
	}
	cout << solution(a, b) << endl;
	return 0;
}