#include <iostream>
#include <algorithm>
using namespace std;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int N;
int arr[20][20];
int arr2[20][20];
int Max = 0;
int vis[20][20];
int cc = 0;
int order[5];

void move(int ind, int arr2[][20]) {
	if (ind == 0) { //위
		for (int j = 0; j < N; j++) {
			int tmp = -1;
			for (int i = 1; i < N; i++) {
				if (arr2[i][j] == 0) continue;
				int ind = i;
				while (ind > 0) {
					if (arr2[ind - 1][j] != 0) { //블록 있으면 더이상 못감 
						break;
					}
					ind--;

				}
				if (arr2[ind][j] == 0) { //이동
					arr2[ind][j] = arr2[i][j];
					arr2[i][j] = 0;
				}
				if (ind == 0) continue;
				if (arr2[ind - 1][j] == arr2[ind][j] && ind-1>tmp) { //바로 위랑 같으면 합쳐짐
					arr2[ind - 1][j] = arr2[ind - 1][j] * 2;
					arr2[ind][j] = 0;
					//vis[ind-1][j]=1;

					tmp = ind - 1; //합쳐진 블록 위치
				}
			}
		}
		//fill(&vis[0][0],&vis[0][0]+20*20,0);
	}

	else if (ind == 1) { //오른쪽
		for (int i = 0; i < N; i++) {
			int tmp = N;
			for (int j = N - 2; j >= 0; j--) {
				if (arr2[i][j] == 0) continue;
				int ind = j;
				while (ind < N - 1) {
					if (arr2[i][ind + 1] != 0) { //블록 있으면 더이상 못감 
						break;
					}
					ind++;

				}
				if (arr2[i][ind] == 0) { //이동
					arr2[i][ind] = arr2[i][j];
					arr2[i][j] = 0;
				}
				if (ind == N - 1) continue;
				if (arr2[i][ind + 1] == arr2[i][ind] && ind + 1 < tmp) { //바로 위랑 같으면 합쳐짐
					arr2[i][ind + 1] = arr2[i][ind + 1] * 2;
					arr2[i][ind] = 0;
					tmp = ind + 1; //합쳐진 블록 위치
				}
			}
		}
	}
	else if (ind == 2) { //아래
		for (int j = 0; j < N; j++) {
			int tmp = N;
			for (int i = N - 1; i >= 0; i--) {
				if (arr2[i][j] == 0) continue;
				int ind = i;
				while (ind < N - 1) {
					if (arr2[ind + 1][j] != 0) { //블록 있으면 더이상 못감 
						break;
					}
					ind++;

				}
				if (arr2[ind][j] == 0) { //이동
					arr2[ind][j] = arr2[i][j];
					arr2[i][j] = 0;
				}
				if (ind == N - 1) continue;
				if (arr2[ind + 1][j] == arr2[ind][j] && ind + 1 < tmp) { //바로 위랑 같으면 합쳐짐
					arr2[ind + 1][j] = arr2[ind + 1][j] * 2;
					arr2[ind][j] = 0;
					tmp = ind + 1; //합쳐진 블록 위치
				}
			}
		}
	}
	else if (ind == 3) { //왼
		for (int i = 0; i < N; i++) {
			int tmp = -1;
			for (int j = 1; j < N; j++) {
				if (arr2[i][j] == 0) continue;
				int ind = j;
				while (ind > 0) {
					if (arr2[i][ind - 1] != 0) { //블록 있으면 더이상 못감 
						break;
					}
					ind--;

				}
				if (arr2[i][ind] == 0) { //이동
					arr2[i][ind] = arr2[i][j];
					arr2[i][j] = 0;
				}
				if (ind == 0) continue;
				if (arr2[i][ind - 1] == arr2[i][ind] && ind - 1 > tmp) { //바로 위랑 같으면 합쳐짐
					arr2[i][ind - 1] = arr2[i][ind - 1] * 2;
					arr2[i][ind] = 0;
					tmp = ind - 1; //합쳐진 블록 위치
				}
			}
		}
	}

}
void func(int cnt, int arr2[][20]) {
	if (cnt == 5) {
		//cc++;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				Max = max(Max, arr2[i][j]);
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		order[cnt] = i;
		int tmpArr[20][20];
		copy(&arr2[0][0], &arr2[0][0] + 20 * 20, &tmpArr[0][0]); //이거 안해줘서 틀림!!! 
		move(i, arr2);
		func(cnt + 1, arr2);
		copy(&tmpArr[0][0], &tmpArr[0][0] + 20 * 20, &arr2[0][0]); //꼭 복구해줘야함. 안그럼 변형된 상태 누적..!!!!

	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	copy(&arr[0][0], &arr[0][0] + 20 * 20, &arr2[0][0]);

	func(0, arr2);
	cout << Max << '\n';

}