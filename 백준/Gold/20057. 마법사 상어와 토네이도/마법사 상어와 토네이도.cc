#include <iostream>
#include <cmath>
using namespace std;
#define Y first
#define X second
int N;
int arr[500][500];
int dy[] = { -2,-1,-1,-1,0,1,1,1,2,0 }; //도착지점 y를 기준으로 
int dx[] = { 0,-1,0,1,-2,-1,0,1,0,-1 };//마지막은 a
double ratio[] = { 0.02,0.1,0.07,0.01,0.05,0.1,0.07,0.01,0.02 }; //a는 포함 x
pair<int,int> now;

void Turn() { //시계방향으로 90도 회전
    int tmp[500][500];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[i][j] = arr[i][j];
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            arr[i][j]=tmp[N-1-j][i];
        }
    }
    int tt=now.Y; //현재 위치의 좌표도 바꿔줘야함!! 주의!! - 틀린지점2
    now.Y=now.X;
    now.X=N-1-tt;
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
    
    now = { N / 2,N / 2 };
    int ind = 1;
    int start = 1;
    int end = N * N;
    int torY[]={0, 1, 0, -1}; //토네이도 방향 
    int torX[]={-1,0,1,0};

    int len = 1;
    int dir = 0;
    int ans = 0;
    bool isEnd = false;
    while (start < end) {
        
        for (int i = 0; i < 2; i++) {
            
            for (int j = 0; j < len; j++) {
                now.X += -1; //토네이도 도착 장소(배열 자체를 계속 회전해주므로 토네이도 방향은 계속 왼쪽으로 하면됨!!) - 틀린지점3
                start++;
                //cout << start << ' ';

                //cout<<now.Y<<' '<<now.X<<' ' << arr[now.Y][now.X] << '\n';
                
                int tmp = arr[now.Y][now.X]; //해당 칸 모래
                //cout << tmp << '\n';
                int sum = 0;
                for (int x = 0; x < 9; x++) {
                    int ny = now.Y + dy[x];
                    int nx = now.X + dx[x];
                    //cout << "ny: " << ny<<' ' << "nx: " << nx << '\n';
                    if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
                        
                        int gone=trunc(arr[now.Y][now.X] * ratio[x]);
                        //cout << "gone: " << gone << '\n';
                        ans += gone;
                        sum += gone;
                    }
                    else {
                        int gone= trunc(arr[now.Y][now.X] * ratio[x]);
                        //cout << "gone: " << gone << '\n';
                        
                        arr[ny][nx] += gone;
                        sum += gone;

                    }
                }

                int left = tmp - sum;
                //cout << "sum: " << sum<<'\n';
                int ny = now.Y + dy[9];
                int nx = now.X + dx[9];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
                    ans += left;
                }
                else {
                    arr[ny][nx] += left;
                }
                arr[now.Y][now.X] = 0;
                if (start == N * N) {
                    isEnd = true;
                    break;
                }

            }
            if (isEnd) {
                break;
            }
            dir++; //방향 
            if (dir == 4) dir = 0;

            //배열 시계방향으로 회전
            Turn(); // - 틀린지점1
            
        }
        
        len++;
    }
    cout << ans;
}