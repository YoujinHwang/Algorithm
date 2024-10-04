#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> row;
vector<int> col;
int Max = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r, c;
	cin >> c >> r;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int t, tmp;
		cin >> t >> tmp;
		if (t == 0) row.push_back(tmp);
		else col.push_back(tmp);
	}
	row.push_back(r);
	col.push_back(c);

	sort(row.begin(), row.end());
	sort(col.begin(), col.end());

	int ind_r = 0;
	int ind_c = 0;
	for (auto s : row) {
		int y = s - ind_r;
		for (auto a : col) {
			int x = a - ind_c;
			Max = max(Max, y * x);
			ind_c = a;
		}
		ind_c = 0; //이거 안해줘서 계속 틀림! 한 row 다 돌렸으면 다시 0으로 돌아와야지!
	
		ind_r = s;
	}
	
	cout << Max;
}
