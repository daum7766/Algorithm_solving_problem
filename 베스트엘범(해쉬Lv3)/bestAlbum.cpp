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
	for (int i = 0; i < genres.size(); i++) {
		//music map�� �帣���� Ƚ���߰�
		music[genres[i]] += plays[i];
		//musiclist map�� �뷡��ȣ�� �÷���Ƚ�� �߰�
		musiclist[genres[i]][i] = plays[i];
	}
	//�帣�� �پ����������� �ݺ�
	while (music.size() > 0) {
		string genre{};
		int max{ 0 };
		//�帣�߿��� ���ϳ����� ã��
		for (auto mu : music) {
			if (max < mu.second) {
				max = mu.second;
				genre = mu.first;
			}
		}
		//2���� �־���ϹǷ� 2���ݺ�
		for (int i = 0; i < 2; i++) {
			int val = 0, ind = -1;
			//�뷡�߿��� ���ϳ����� ã��
			for (auto ml : musiclist[genre]) {
				if (val < ml.second) {
					val = ml.second;
					ind = ml.first;
				}
			}
			//���� �뷡�� 0~1��ۿ����ٸ� �ݺ��� Ż��
			if (ind == -1)	break;
			//������ ����Ʈ�� �뷡��ȣ �߰�
			answer.push_back(ind);
			musiclist[genre].erase(ind);
		}
		//map ���� ����� �帣����
		music.erase(genre);
	}
	return answer;
}



int main(){
	vector<string> genres{ "classic","pop","classic","pop","classic","classic" };
	vector<int> plays{ 400,600,150,2500,500,500 };
	vector<int> result = solution(genres, plays);
	for (int i = 0; i < result.size(); i++)
		cout << result.at(i) << endl;

	return 0;
}