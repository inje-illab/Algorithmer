#include <iostream>

#define MAX_NUM 1000000

using namespace std;

void basicSolve(int num) {
	bool prime = 1;
	for (int i = 2; i*i < num; ++i) {		// 2부터 증가시켜가며 1까지
		if (num%i == 0) {		// 입력받은 값을 나눴을 때 나눠떨어지면 
			prime = 0;			// 소수가 아님
			break;
		}
	}
	if (prime)
		cout << "소수";
	else
		cout << "합성수";
}

void eratosthenes_sieve(int start, int end) {	// 에라토스테네스의 체 (여러 개의 소수를 한꺼번에 검사할 때 유용)
	bool sieve[MAX_NUM] = { 1, 1 };	// 0과 1은 소수가 아닌 것으로 판별
	for (int i = 2; i*i <= MAX_NUM; ++i) {
		if (sieve[i]) continue;	// 이미 1 (if안에서는 true)이면 넘어간다.
		for (int j = i * i; j < MAX_NUM; j += i)	// j가 i^2로 시작하는 이유 : 이미 이전 단계에서 i*(i-1)까지 지워져있기 때문!
			sieve[j] = 1;	// 남은 i의 배수를 모두 지운다.
	}

	int count = 0;
	for (int i = start; i < end; ++i) {
		if (!sieve[i]) {
			cout << i << "\t";
			if (++count % 10 == 0) cout << "\n\t";
		}
	}
}

int main() {
	int tmp1, tmp2;
	cout << "\n\t소수인지 알고 싶은 숫자 입력! >> ";
	cin >> tmp1;
	cout << "\t" << tmp1 << "는 >> ";
	basicSolve(tmp1);
	rewind(stdin);
	cout << "\n\n\t일정 범위 안의 소수 모두 출력 : 범위의 최소 최대값 입력 >> ";
	cin >> tmp1 >> tmp2;
	cout << "\t" << tmp1 << " 이상 " << tmp2 << " 미만의 소수\n\t>> ";
	eratosthenes_sieve(tmp1, tmp2);
	system("pause");
}