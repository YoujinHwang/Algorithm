#include <iostream>
#include <climits>
using namespace std;
string arr[50];
int vis_r[50];
int vis_c[50];
int n, m;
int ans=0;



void Row() {
	for (int i = 0; i < n; i++) {
		if (vis_r[i] == 0) {
			for (int j = 0; j < m; j++) {
				if (vis_c[j]==0) {
					
					ans++;
					vis_r[i] = 1;
					vis_c[j] = 1;
					break;
				}
			}
			
		}
		
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'X') {
				
				vis_r[i] = 1;
				vis_c[j] = 1;
			}
		}
	}
	Row();

	for (int i = 0; i < n; i++) {
		if (vis_r[i] == 0) ans++;
	}
	for (int i = 0; i < m; i++) {
		if (vis_c[i] == 0) ans++;
	}
	cout << ans;
}