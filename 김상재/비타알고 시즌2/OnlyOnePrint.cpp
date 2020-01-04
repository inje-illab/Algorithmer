#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long calculate(int N, vector<int> a) {
	long sum = 0;
	int temp = 0, j = 0;
	for (int i = 0; i < N; i++) {
		for (; j < i; j++) {
			temp += a[j]; // 대기시간 합
		}
		sum += temp + a[i]; // i번째 학생 대기시간 + 프린트 시간 합
	}
	return sum;
}

int main() {
	int N, temp;
	cin >> N;
	vector<int> a;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end()); //대기 시간을 줄이기 위해 프린트 시간이 가장 작은 순으로 정렬
	cout << calculate(N, a)<<endl;
	system("pause");
}
