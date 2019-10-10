#include <iostream>
using namespace std;
int main() {
	int heroNum, result = 5; // 최초 영웅 선택 번호
	bool heroArr[87] = {false, }; // 0:empty, 1~87
	for(int i = 0; i < 4; i++){
		cin >> heroNum;
		heroArr[heroNum] = true;
	}
	for(int i = 0; i < 5; i++){
		cin >> heroNum;
		if(heroArr[heroNum]) // 해당 영웅이 선택 된 상태일 경우
			result--;
	}
	cout << result;
	return 0;
}