#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// two pointer 방식
int binarySearch(vector<int>& seq, int data) {
	int l = 0, r = seq.size() - 1;		// l = left edge(seq[0]) to right pointer , r = right edge(seq[seq.size()-1]) to left pointer
	while (l <= r) {			// left pointer가 right pointer를 지나치기 전까지  (l > r이 되는 순간, ****rl****의 모습)
		int mid = (l + r) / 2;		// 현재 남은 배열의 중간값을 mid로 설정
		if (seq[mid] == data) return mid;	// mid와 원하는 값이 같으면 return
		else if (seq[mid] < data) l = mid + 1;	// mid가 원하는 값보다 작다면, mid 아래론 필요없음 -> left pointer를 mid+1로 땡기기
		else r = mid - 1;		// mid가 원하는 값보다 크다면, mid 위로는 필요없음 -> right pointer를 mid-1로 땡기기
	}
	return -1;	// while 돌고나서도 값이 안 나오면, 걍 값이 없는거임
}

void showArr(vector<int> arr) {		// 배열을 보기좋게 보여주는 함수
	int cnt = arr.size();		// vector의 사이즈 : size() 멤버함수
	cout << "[";
	for (int i = 0; i < cnt; i++) {
		if (i != cnt - 1) cout << arr[i] << ", ";		// 끝 전까지는 ,로 구분
		else cout << arr[i] << "]\n";					// 끝에는 , 없음
	}
}

int main() {
	int cnt, tmp;
	vector<int> vArr;
	cout << "\n\n\t몇 개의 값을 입력받을까요?\n\t>> ";
	cin >> cnt;
	cout << "\n\t띄어쓰기로 구분하여 " << cnt << "개의 배열 값을 입력\n\t>> ";
	for (int i = 0; i < cnt; i++) {
		cin >> tmp;
		vArr.push_back(tmp);		// vector 템플릿 -> push_back은 뒤에 동적으로 추가하는 함수
	}
	cout << "\n\t입력한 배열 X = ";
	showArr(vArr);
	sort(vArr.begin(), vArr.end());	// algorithm 헤더 -> 정렬하기 (default = Ascending order ; 오름차순)
	cout << "\n\t정렬된 배열 X = ";
	showArr(vArr);

	cout << "\n\t배열 내 순서를 찾고 싶은 숫자는? >> ";
	rewind(stdin);	// stdin 내 버퍼 초기화 
	cin >> tmp;
	tmp = binarySearch(vArr, tmp);  // binarysearch 진행
	if (tmp > -1) cout << "\n\t" << tmp + 1 << "번째 원소입니다.\n\n\t";
	else cout << "원소를 찾지 못했습니다.\n\n\t";	// -1 출력은 없다는 뜻
	system("pause");
}