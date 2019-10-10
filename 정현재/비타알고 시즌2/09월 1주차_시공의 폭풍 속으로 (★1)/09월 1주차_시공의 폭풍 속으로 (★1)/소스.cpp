#include <iostream>
using namespace std;
int main() {
	int Selection[4], hope[5], count = 5;
	for (int i = 0; i < 4; i++) cin >> Selection[i];
	for (int i = 0; i < 5; i++) cin >> hope[i];
	for (int i = 0; i < 5; i++) for (int j = 0; j < 4; j++) if (hope[i] == Selection[j]) { count--; continue; }
	cout << count;
	return 0;
}