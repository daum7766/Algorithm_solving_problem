#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	stack<int> st;
	bool check = true;
	//리스트를 뒤에서부터 순회하기
	for (int j = heights.size() - 1; j >= 0; j--) {
		//자기자신과 비교할필요가 없기때문에 비교하는것의 앞부터 계산
		for (int i = j - 1; i >= 0; i--) {
			//제일뒤에꺼보다 앞에타워가 큰경우
			if (heights.at(i) > heights.at(j)){
				//스택에 몇번째 타워인지 넣기
				st.push(i + 1);
				//조건문 비활성화
				check = false;
				//반복문 나가기
				break;
			}
		}
		//만약 앞터워가 큰게없다면
		//스택에 없다고 0을 넣기
		if (check)
			st.push(0);
		check = true;
	}
	//스택이 빌동안 정답에 푸쉬
	while (!st.empty()) {
		answer.push_back(st.top());
		st.pop();
	}
	return answer;
}

void print(vector<int> heights, vector<int> answer)
{
	vector<int> t = solution(heights);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
		if (answer[i] != t[i]){
			cout << "틀림" << endl;
			return;
		}
	}
	cout << "정답" << endl;
}

int main()
{
	print({ 6, 9, 5, 7, 4 }, { 0,0,2,2,4 });
	print({ 3,9,9,3,5,7,2 }, { 0,0,0,3,3,3,6 });
	print({ 1,5,3,6,7,6,5 }, { 0,0,2,0,0,5,6 });
	return 0;
}