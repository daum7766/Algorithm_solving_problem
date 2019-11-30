#include <vector>
#include <iostream>
using namespace std;

//�ִ����� ���ϱ�
int gcd(int a, int b) { return !(a % b) ? b : gcd(b, a % b); }
//�ּ� ����� ���ϱ�
int lcm(int a, int b) { return a * b / gcd(a, b); }

int solution(vector<int> arr) {
	int answer = arr[0];
	// 2���� �ּҰ������ ���ؼ� �������� �ٽ� �ּҰ������ ���Ѵ�.(���⵵ O(N))
	for (int i = 1; i < arr.size(); i++)	answer = lcm(answer, arr[i]);
	return answer;
}

void print(vector<int> arr, int answer) {
	int t = solution(arr);
	if (t == answer)	cout << "����" << endl;
	else	cout << "����" << endl;
}

int main() {
	print({ 2, 6, 8, 14 }, 168);
	print({ 1, 2, 3 }, 6);
	return 0;
}