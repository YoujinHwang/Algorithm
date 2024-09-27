#include <iostream>
#include <climits>
#include <string>

using namespace std;
int R, C;
int arr[1000][1000];
int vis[1000][1000];
long long ans;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
string Right;
string Left;

string path;
int Min_i, Min_j;
void goRight() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C - 1; j++) {
            if (i % 2 == 0) {
                path += "R";
            }
            else {
                path += "L";
            }
        }
        if (i == R - 1) break;
        path += "D";
    }
    cout << path;
}
void goDown() {
    for (int j = 0; j < C; j++) {
        for (int i = 0; i < R - 1; i++) {
            if (j % 2 == 0) {
                path += "D";
            }
            else {
                path += "U";
            }
        }
        if (j == C - 1) break;
        path += "R";
    }
    cout << path;
}
string ff(int ind) {
    string a;
    if (ind == 0) { //짝수행에 있을때
       
        a = "DR";
        for (int i = 0; i < C / 2-1; i++) {
            a += "URDR";
        }
        a.insert(Min_j * 2, "R");
        //cout << C * 2 - 3 << '\n';
        a=a.substr(0, C * 2 - 2);
        //cout << a << '\n';
    }
    else {
        if (C == 2) {
            a = "RD";
            return a;
        }
        a="D";
        for (int i = 0; i < C / 2; i++) {
            a += "RURD";
        }
        a.insert(Min_j * 2, "R");
        a=a.substr(0, C * 2 - 2);

    }
    return a;
}

void findPath() {
    if (Min_i % 2 == 0) {
        for (int i = 0; i <= R - 1; i++) {
           
            if (i < Min_i) {
                if (i % 2 == 0) {
                    path += Right;
                }
                else {
                    path += Left;
                }
            }

            else if (i == Min_i) {
                //func(path, 0);
                path += ff(0);
                i += 1;
                if (i == R - 1) {
                    //cout << i << '\n';
                    cout << path;
                    return;
                }
            }

            else {
                if (i % 2 == 0) {
                    path += Left;
                }
                else {
                    path += Right;
                }
            }
            if (i == R - 1) break;
            path += 'D';
        }

    }
    else {
        for (int i = 0; i <= R - 1; i++) {
           
            if (i == Min_i-1) { //i==Min_i가 아니라 i==Min_i-1로 해야함!
                path += ff(1);
                i += 1;
                if (i == R - 1) {
                    cout << path;
                    return;
                }

            }
            else if (i < Min_i-1) {
                if (i % 2 == 0) {
                    path += Right;
                }
                else {
                    path += Left;
                }
            }

          
            else {
                if (i % 2 == 0) {
                    path += Left;
                }
                else {
                    path += Right;
                }
            }
            if (i == R - 1) break;
            path += 'D';
        }
    }
    cout << path;
}
int Min = INT_MAX;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if ((i == 0 && j == 0) || (i == R - 1 && j == C - 1)) continue;
            if ((i + j) % 2 == 1 && Min > arr[i][j]) {
                Min_i = i;
                Min_j = j;
                Min = arr[i][j];
            }
        }
    }
    if (R % 2 == 1) {
        goRight();
        return 0;
    }
    else if (C % 2 == 1) {
        goDown();
        return 0;
    }
    else { //행,열 둘 다 짝수
        
        for (int i = 0; i < C - 1; i++) {
            Right += "R";
        }
        for (int i = 0; i < C - 1; i++) {
            Left += "L";
        }

        findPath();
    }

}