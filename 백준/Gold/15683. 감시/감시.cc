#include <bits/stdc++.h>
using namespace std;
//int t_1, t_2,t_3,t_4;
int n, m;
//int max_1, max_2;
int arr2[8][8];
int arr[8][8];
//int cctv[6];

vector<pair <int, int>> cctv;


int main() {
	int cnt = 0; //cctv 개수
	
	cin >> n >> m;
	//cin.ignore();
	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> num; //입력 받는 부분은 한 번만 실행되어야 함. 즉, 입력받아서 할당한 배열을 복사해서 다른 배열에 한번 더 저장하고, 복사한 배열을 수정하고 반복 초기화해야함.
			arr2[i][j] = num;              
			if (num != 6 && num != 0) {
				//cnt++; 일일이 해줄 필요 없음. cctv.size()로 하면 됨
				cctv.push_back({ i,j });
			}
		}
	}
	
	cnt = cctv.size(); 
	long long c_num = pow(4, cnt);
	int min_total = 64;

	for (long long i = 0; i < c_num; i++) {
		int total = 0;
		long long temp = i;

		for (int q = 0; q < n; q++) { //매번 초기화를 해주는거 잊지말기!! 새로운 경우로 될때마다 초기화 다시 해줘야함(처음에 한번만 해줘서 틀림)
			for (int w = 0; w < m; w++) {
				arr[q][w] = arr2[q][w];
			}
		}

		for (int j = 0; j < cnt; j++) {
			int dir = temp % 4;
			temp /= 4;
			int x = cctv[j].first;
			int y = cctv[j].second;
			if (arr2[x][y]==1) {
				if (dir == 0) {//왼쪽
					for (int z = y - 1; z >= 0; z--) {
						if (arr[x][z] == 6) break;
						if (arr[x][z] != 6 && arr[x][z] != 0) continue; //이거 빠트림. cctv인 경우 -1로 할당하면 안됨. 해당 cctv 차례에서 cctv 종류 판별 불가
						arr[x][z] = -1;
					}
				}
				else if (dir == 1) {//오른쪽
					for (int z = y+1; z<m; z++) {
						if (arr[x][z] == 6) break;
						if (arr[x][z] != 6 && arr[x][z] != 0) continue;
						arr[x][z] = -1;
					}
				}
				else if (dir == 2) { //위쪽
					for (int z = x-1; z >=0; z--) {
						if (arr[z][y] == 6) break;
						if (arr[z][y] != 6 && arr[z][y] != 0) continue;
						arr[z][y] = -1;
					}
				}
				else {//아래쪽
					for (int z = x+1; z < n; z++) {
						if (arr[z][y] == 6) break;
						if (arr[z][y] != 6 && arr[z][y] != 0) continue;
						arr[z][y] = -1;
					}
				}
			}
			else if (arr2[x][y] == 2) {
				if (dir == 0||dir==1) {//왼쪽, 오른쪽
					for (int z = y - 1; z >= 0; z--) { 
						if (arr[x][z] == 6) break;
						if (arr[x][z] != 6 && arr[x][z] != 0) continue;
						arr[x][z] = -1;
					}
					for (int z = y + 1; z < m; z++) {
						if (arr[x][z] == 6) break;
						if (arr[x][z] != 6 && arr[x][z] != 0) continue;
						arr[x][z] = -1;
					}
				}
				else { //위쪽, 아래쪽
					for (int z = x - 1; z >= 0; z--) {
						if (arr[z][y] == 6) break;
						if (arr[z][y] != 6 && arr[z][y] != 0) continue;
						arr[z][y] = -1;
					}
					for (int z = x + 1; z < n; z++) {
						if (arr[z][y] == 6) break;
						if (arr[z][y] != 6 && arr[z][y] != 0) continue;
						arr[z][y] = -1;
					}
				}
			}
			else if (arr2[x][y] == 3) {
				if (dir == 0) { //왼쪽, 위쪽
					for (int z = y - 1; z >= 0; z--) {
						if (arr[x][z] == 6) break;
						if (arr[x][z] != 6 && arr[x][z] != 0) continue;
						arr[x][z] = -1;
					}
					for (int z = x - 1; z >= 0; z--) {
						if (arr[z][y] == 6) break;
						if (arr[z][y] != 6 && arr[z][y] != 0) continue;
						arr[z][y] = -1;
					}
				}
				else if (dir == 1) { //오른쪽, 위쪽
					for (int z = y + 1; z < m; z++) {
						if (arr[x][z] == 6) break;
						if (arr[x][z] != 6 && arr[x][z] != 0) continue;
						arr[x][z] = -1;
					}
					for (int z = x - 1; z >= 0; z--) {
						if (arr[z][y] == 6) break;
						if (arr[z][y] != 6 && arr[z][y] != 0) continue;
						arr[z][y] = -1;
					}
				}
				else if (dir == 2) { //왼쪽, 아래쪽
					for (int z = y - 1; z >= 0; z--) {
						if (arr[x][z] == 6) break;
						if (arr[x][z] != 6 && arr[x][z] != 0) continue;
						arr[x][z] = -1;
					}
					for (int z = x + 1; z < n; z++) {
						if (arr[z][y] == 6) break;
						if (arr[z][y] != 6 && arr[z][y] != 0) continue;
						arr[z][y] = -1;
					}
				}
				else { //오른쪽, 아래쪽
					for (int z = y + 1; z < m; z++) {
						if (arr[x][z] == 6) break;
						if (arr[x][z] != 6 && arr[x][z] != 0) continue;
						arr[x][z] = -1;
					}
					for (int z = x + 1; z < n; z++) {
						if (arr[z][y] == 6) break;
						if (arr[z][y] != 6 && arr[z][y] != 0) continue;
						arr[z][y] = -1;
					}
				}
			}
			else if (arr2[x][y] == 4) {
				if (dir == 0) { //왼쪽, 위쪽,오른쪽
					for (int z = y - 1; z >= 0; z--) {
						if (arr[x][z] == 6) break;
						if (arr[x][z] != 6 && arr[x][z] != 0) continue;
						arr[x][z] = -1;
					}
					for (int z = x - 1; z >= 0; z--) {
						if (arr[z][y] == 6) break;
						if (arr[z][y] != 6 && arr[z][y] != 0) continue;
						arr[z][y] = -1;
					}
					for (int z = y + 1; z < m; z++) {
						if (arr[x][z] == 6) break;
						if (arr[x][z] != 6 && arr[x][z] != 0) continue;
						arr[x][z] = -1;
					}
				}
				else if (dir == 1) { //오른쪽, 위쪽,아래쪽
					for (int z = y + 1; z < m; z++) {
						if (arr[x][z] == 6) break;
						if (arr[x][z] != 6 && arr[x][z] != 0) continue;
						arr[x][z] = -1;
					}
					for (int z = x - 1; z >= 0; z--) {
						if (arr[z][y] == 6) break;
						if (arr[z][y] != 6 && arr[z][y] != 0) continue;
						arr[z][y] = -1;
					}
					for (int z = x + 1; z < n; z++) {
						if (arr[z][y] == 6) break;
						if (arr[z][y] != 6 && arr[z][y] != 0) continue;
						arr[z][y] = -1;
					}
				}
				else if (dir == 2) { //왼쪽, 아래쪽, 오른쪽
					for (int z = y - 1; z >= 0; z--) {
						if (arr[x][z] == 6) break;
						if (arr[x][z] != 6 && arr[x][z] != 0) continue;
						arr[x][z] = -1;
					}
					for (int z = x + 1; z < n; z++) {
						if (arr[z][y] == 6) break;
						if (arr[z][y] != 6 && arr[z][y] != 0) continue;
						arr[z][y] = -1;
					}
					for (int z = y + 1; z < m; z++) {
						if (arr[x][z] == 6) break;
						if (arr[x][z] != 6 && arr[x][z] != 0) continue;
						arr[x][z] = -1;
					}
				}
				else { //왼쪽, 아래쪽, 위쪽
					for (int z = y - 1; z >= 0; z--) {
						if (arr[x][z] == 6) break;
						if (arr[x][z] != 6 && arr[x][z] != 0) continue;
						arr[x][z] = -1;
					}
					for (int z = x + 1; z < n; z++) {
						if (arr[z][y] == 6) break;
						if (arr[z][y] != 6 && arr[z][y] != 0) continue;
						arr[z][y] = -1;
					}
					for (int z = x - 1; z >= 0; z--) {
						if (arr[z][y] == 6) break;
						if (arr[z][y] != 6 && arr[z][y] != 0) continue;
						arr[z][y] = -1;
					}
				}
			}
			else if (arr2[x][y] == 5) { //왼쪽, 위쪽,오른쪽, 아래쪽
				
				for (int z = y - 1; z >= 0; z--) {
					if (arr[x][z] == 6) break;
					if (arr[x][z] != 6 && arr[x][z] != 0) continue;
					arr[x][z] = -1;
				}
				for (int z = x - 1; z >= 0; z--) {
					if (arr[z][y] == 6) break;
					if (arr[z][y] != 6 && arr[z][y] != 0) continue;
					arr[z][y] = -1;
				}
				for (int z = y + 1; z < m; z++) {
					if (arr[x][z] == 6) break;
					if (arr[x][z] != 6 && arr[x][z] != 0) continue;
					arr[x][z] = -1;
				}
				for (int z = x + 1; z < n; z++) {
					if (arr[z][y] == 6) break;
					if (arr[z][y] != 6 && arr[z][y] != 0) continue;
					arr[z][y] = -1;
				}
			}

		}
		for (int r = 0; r < n; r++) {
			for (int d = 0; d < m; d++) {
				if (arr[r][d] == 0)
					total++;
			}
		}
		
		min_total = min(total, min_total);
	}
	cout << min_total << '\n';
	return 0;

}