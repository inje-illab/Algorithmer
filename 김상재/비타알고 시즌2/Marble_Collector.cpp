#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

unsigned long long calculate(unsigned long long N, int K, vector<int> box) {
	unsigned long long cnt = 0;
	for (int i = 0; i < K; i++) {
		cnt += N / box[i];
		N %= box[i];
		if (N == 0) break;
	}
	return cnt;
}

int main() {
	unsigned long long N;
	int K;
	cin >> N >> K;
	if (K < 2 || K > 30) return 0;
	vector<int> box;
	for (int i = 0; i < K; i++) {
		int temp;
		cin >> temp;
		if(i == 0 && temp != 1) return 0;
		if (i > 0) {
			if (temp <= box[i - 1]) return 0;
			if  e/ box[i - 1] <= 1 && temp%box[i - 1] != 0) return 0;
		}
		box.push_back(temp);
		
	}
	reverse(box.begin(), box.end());
	cout << calculate(N, K, box) << endl;
}
