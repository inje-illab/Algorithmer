#include <iostream>
using namespace std;

int d[101010];
int fiboTopDown(int n) {		// 재귀함수
	if (n <= 1) return 1;			// n(피보나치 순서) 이 1 이하로 떨어질 경우 1로 출력
	int &res = d[n];					// res를 현재 피보나치 순서의 수로 설정
	if (res) return res;				// 
	return res = fiboTopDown(n - 1) + fiboTopDown(n - 2);
}

int fiboBottomUp(int n) {
	int dd[101010] = { 1,1 };
	for (int i = 2; i <= n; ++i)
		dd[i] = dd[i - 1] + dd[i - 2];
	return dd[n];
}

int main() {
	cout << "\n\t몇 번째 피보나치 수를 보여드릴까요?\n\t(짝수 : topdown방식, 홀수:bottomup방식)\n\t";
	int aa;
	cin >> aa;
	cout << "\t" << aa << "번째 피보나치 수 = ";
	if (aa % 2 == 0) cout << fiboTopDown(aa) << "\n\tTopDown방식 이용";
	else cout << fiboBottomUp(aa) << "\n\tBottomUp방식 이용\n\n\t";
	system("pause");
}