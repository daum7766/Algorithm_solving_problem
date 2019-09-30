#include <string>
#include <vector>
#include <iostream>
#include <map>//�ؽ��� ���

using namespace std;


vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	//�� �帣���� Ƚ������
	map<string, int> music;
	//�� �帣���� �����뷡�� ����� ��������
	map<string, map<int, int>> musiclist;
	//���� ����Ʈ��ŭ �ݺ�
	for (int i = 0; i < genres.size(); i++)
	{
		//music map�� �帣���� Ƚ���߰�
		music[genres[i]] += plays[i];
		//musiclist map�� �뷡��ȣ�� �÷���Ƚ�� �߰�
		musiclist[genres[i]][i] = plays[i];
	}
	string genre;
	int max = 0;
	//�帣�� �پ����������� �ݺ�
	while (music.size() > 0)
	{
		//�帣�߿��� ���ϳ����� ã��
		for (auto mu : music)
		{
			if (max < mu.second)
			{
				max = mu.second;
				genre = mu.first;
			}
		}
		int count = 0;
		//2���� �־���ϹǷ� 2���ݺ�
		for (int i = 0; i < 2; i++)
		{
			int val = 0;
			int ind = -1;
			//�뷡�߿��� ���ϳ����� ã��
			for (auto ml : musiclist[genre])
			{
				if (val < ml.second)
				{
					val = ml.second;
					ind = ml.first;
				}
				else if (val == ml.second)
				{
					if (ind > ml.first)
					{
						ind = ml.first;
					}
				}
			}
			//���� �뷡�� 1��ۿ����ٸ� �ݺ��� Ż��
			if (ind == -1)
			{
				break;
			}
			//������ ����Ʈ�� �뷡��ȣ �߰�
			answer.push_back(ind);

			musiclist[genre].erase(ind);
			val = 0;
			ind = -1;
		}
		//map ���� ����� �帣����
		max = 0;
		music.erase(genre);
	}


	return answer;
}



int main()
{
	string gestr[] = { "classic","pop","classic","pop","classic","classic" };
	int plint[] = { 400,600,150,2500,500,500 };
	vector<string> genres;
	vector<int> plays;
	for (int i = 0; i < 6; i++)
	{
		genres.push_back(gestr[i]);
		plays.push_back(plint[i]);
	}
	vector<int> result = solution(genres, plays);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result.at(i) << endl;
	}


	return 0;
}