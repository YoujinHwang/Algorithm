#include <string>
#include <vector>

using namespace std;


int solution(int n, vector<int> tops) {
    int answer = 0;
    //int dp[n+1];
    
//     if(tops[0]) {
//         dp[1]=4;
//     }
//     else {
//         dp[1]=3; 
//     }
//     if(tops[1]) {
//         if(tops[0]) {
//             dp[2]=dp[1]*3+3;
//         }
//         else {
//             dp[2]=dp[1]*3+2;
//         }
        
//     }
//     else {
//          if(tops[0]) {
//             dp[2]=dp[1]*2+3;
//         }
//         else {
//             dp[2]=dp[1]*3+2;
//         }
//     }
//     for(int i=3;i<=n;i++) {
//         if(tops[i-1]) {
//             if(tops[i-2]) {
//                 dp[i]=(dp[i-1]*3%10007+dp[i-1]/3*2%10007)%10007;
//             }
//             else {
//                 dp[i]=(dp[i-1]*3%10007+dp[i-2]%10007)%10007;
//             }
//         }
//         else {
//             if(tops[i-2]) {
//                 dp[i]=(dp[i-1]*2%10007+dp[i-1]/3*2%10007)%10007;
//             }
//             else {
//                 dp[i]=(dp[i-1]*2%10007+dp[i-2]%10007)%10007;
//             }
            
//         }
//     }
//     answer=dp[n];
    
    int dp[2*n+1];
    dp[0]=1;
    if(tops[0]) dp[1]=3;
    else dp[1]=2;
    for(int i=2;i<2*n+1;i++) {
        if(i%2==0) {
            dp[i]=(dp[i-1]+dp[i-2])%10007;
        }
        else {
            if(tops[i/2]) {
                dp[i]=(dp[i-1]*2+dp[i-2])%10007;
            }
            else {
                dp[i]=(dp[i-1]+dp[i-2])%10007;
            }
        }
    }
    answer=dp[2*n];
    return answer;
}