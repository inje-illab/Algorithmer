#include <iostream>
using namespace std;
bool binaryReducer(unsigned long long int arg) {		// 동적계획법 풀이
	if (arg % 2 == 0 && arg > 2) return binaryReducer(arg / 2);
	else if (arg / 2 == 1 || arg / 2 == 0) return 1;
	else	return 0;
}
int main() {
	unsigned long long int input;		// 10^18 정수를 소화할 수 있는 자료형
	cin >> input;
	if (binaryReducer(input)) cout << "Yes";
	else cout << "No";
}