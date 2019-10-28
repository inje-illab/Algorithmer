#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	int N, x, y, max[2][2], temp[2][2], index[2];
	float t_Sum, m_Sum;
	vector<vector<int>> arr; // 2차원 벡터 생성
	cin >> N; // 인원 수 입력
	arr.assign(N, vector<int>(2, 0)); // 벡터 공간 설정
	for (int i = 0; i < N; i++){
		cin >> x >> y;
		arr[i][0] = x;
		arr[i][1] = y;
	}
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			max[i][j] = arr[i][j]; // 최댓값 기초값으로 설정
		}
		index[i] = i + 1; // 기초 인덱스 값 설정
	}

	m_Sum = powf(max[0][0] - max[1][0],2) + powf(max[0][1] - max[1][1], 2); // 최댓값 좌표 길이 설정
	for (int i = 0; i < N; i++){  
		temp[0][0] = arr[i][0];
		temp[0][1] = arr[i][1];
		for (int j = 0; j < N; j++){
			if (j != i){
				temp[1][0] = arr[j][0];
				temp[1][1] = arr[j][1];
				t_Sum = powf(temp[0][0] - temp[1][0], 2) + powf(temp[0][1] - temp[1][1], 2); // 2개의 좌표 길이를 설정
 				if (m_Sum < t_Sum){ // 현재 최댓값의 좌표 길이와 비교
					m_Sum = t_Sum; // 현재 좌표길이가 더 클 경우 최댓값 변경
					index[0] = i + 1; // 인덱스 변경
					index[1] = j + 1;
				}
			}
		}
	}
	cout << index[0] << ' ' << index[1] << endl; // 최댓값 인덱스 출력
}
