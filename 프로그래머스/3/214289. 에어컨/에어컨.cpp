#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    t1+=10;
    t2+=10;
    temperature+=10;
    
    int answer = 0;
    int Max=a*1000;
    int n=onboard.size();
    int dp[1000][52];
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 52; ++j) {
            dp[i][j] = Max;  // 모든 dp 값을 Max로 초기화
        }
    }
    dp[0][temperature]=0; //이 부분 빠트리지 말고 주의하기! dp[0][]을 모두 0으로 초기화하는 것이 아님!
    for(int i=1;i<n;i++) {
        int st;
        int en;
        int MinT=min(t1,temperature);
        int MaxT=max(t2,temperature);
        if(onboard[i]) {
            st=t1;
            en=t2;
        }
        else {
            st=MinT;
            en=MaxT;
        }
        for(int j=st;j<=en;j++) {
            //if(j==0) continue;
            if(j-1>=MinT) {
                if(temperature<=j-1) {
                    dp[i][j]=min(dp[i-1][j-1]+a,dp[i-1][j]+b);
                }
                else {
                    dp[i][j]=min(dp[i-1][j-1],dp[i-1][j]+b);
            
                }
            }
            if(j+1<=MaxT) {
                if(temperature>=j+1) {
                    dp[i][j]=min(dp[i][j],dp[i-1][j+1]+a);
                }
                else {
                    dp[i][j]=min(dp[i][j],dp[i-1][j+1]);
                }
            }
            // if(temperature<j-1) {
            //     dp[i][j]=min(dp[i-1][j-1]+a,dp[i-1][j]+b);
            //     //if(j<50)
            //     //if(j>0)
            //         dp[i][j]=min(dp[i][j],dp[i-1][j+1]);
            // }
            // else if(temperature>j) {
            //     dp[i][j]=min(dp[i-1][j+1]+a,dp[i-1][j]+b);
            //     if(j>0)
            //         dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            // }
            if(temperature==j) {
                // dp[i][j]=min(dp[i-1][j],dp[i-1][j+1]);
                // if(j>0)
                dp[i][j]=min(dp[i][j],dp[i-1][j]);
            }
            // else if(temperature==j) {
            //     dp[i][j]=dp[i-1][j-1];
            // }
            
        }
    }
    answer=*min_element(dp[n-1], dp[n-1]+51);

    return answer;
}


