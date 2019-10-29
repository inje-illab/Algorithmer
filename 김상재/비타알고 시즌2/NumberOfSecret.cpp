#include <iostream>
using namespace std;
bool Check_SecretNumber(long input); //비밀의 수인지 판별하는 함수

int main() {
	long input; // 10^18 수를 받기 위해 long 자료형 사용
	cin >> input;
	if (Check_SecretNumber(input)) //비밀의 수인지 판별
		cout << "Yes" << endl; // 비밀의 수일 경우 "Yes" 출력
	else cout << "No" << endl; // 비밀의 수가 아닐 경우 "No" 출력
	return 0;
}

bool Check_SecretNumber(long input){
	while (input > 2){ // 2이하는 모두 true, input값이 2이하가 될 때까지 반복문 실행
		input /= 2; // input 값을 2 나눔
		if (input % 2 != 0) return false; // 나눈 값을 2로 나눴을 때 0이 아닐 경우(2의 제곱이 아닌 경우)  false 반환
	}
	return true; // 정상적으로 루프가 돌았을 경우 (2의 제곱인 경우) true 반환
}
