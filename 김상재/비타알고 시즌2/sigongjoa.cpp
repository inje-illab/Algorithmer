#include <iostream>
#include <algorithm>
#include <vector>
#define TEAM_MEMBERS 4 // 팀 멤버 수 정의
#define MY_PICK_CNT 5 // 내가 원하는 영웅의 수 정의
using namespace std;

int main() {
	vector<int> iaTeam; // 팀 멤버들이 선택할 영웅 목록 벡터
	vector<int> iaMy_pick; // 내가 원하는 영웅의 목록 벡터
	int cnt = MY_PICK_CNT; // 내가 원하는 영웅의 수 중 선택 가능한 영웅의 수(기본 5개)
	int temp;
	for (int i = 0; i < TEAM_MEMBERS; i++) {
		cin >> temp; // 팀원 픽 입력
		if(find(iaTeam.begin(), iaTeam.end(), temp) == iaTeam.end()) //중복된 값이 있을 경우 i를 감소시켜 다시 입력받게 함.
			iaTeam.push_back(temp);  // 없을 경우 벡터 값 삽입
		else i--;
	}
	 
	for (int i = 0; i < MY_PICK_CNT; i++) {
		cin >> temp; // 내가 원하는 픽 입력
		if (find(iaMy_pick.begin(), iaMy_pick.end(), temp) == iaMy_pick.end()) { // 입력받은 값이 목록에 이미 있는지 탐색
			iaMy_pick.push_back(temp); // 없을 경우 벡터 값 삽입
			if (find(iaTeam.begin(), iaTeam.end(), temp) != iaTeam.end()) { // 내가 원하는 픽 입력할 떄마다 팀원들이 선택한 영웅 탐색
				cnt--;// 내가 입력한 픽이 이미 있으면 내가 선택 가능한 영웅의 수 감소시켜줌.
			}
		}
	}
	cout << cnt << endl; //결과 출력
	return 0;
}
