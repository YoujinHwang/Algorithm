#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int n=targets.size();
    sort(targets.begin(), targets.end());
    int st,en;
    for(int i=0;i<n;i++) {
        
        if(i==0) {
            en=targets[i][1];
            answer++;
            continue;
        }
        if(targets[i][0]>=en) {
            st=targets[i][0];
            en=targets[i][1];
            answer++;
        }
        else {
            st=targets[i][0];
            if(targets[i][1]<=en) {
                en=targets[i][1];
            }
        }
        
    }
    //int i=0;
    // while(1)
    // {
    //     int m=targets[i][1];
    //     answer++;
    //     //cout<<m<<' '<<answer<<'\n';
    //     int j;
    //     for(j=i+1;j<n;j++) {
    //         if(targets[j][0]<m) continue;
    //         i=j;
    //         break;
    //     }
    //     if(i==n-1) {
    //         answer++;
    //         break;
    //     }
    //     if(j==n) break; //j==n-1로 하지 않도록 주의하기
    // }    
    
    // for(auto s:targets) {
    //     for(auto a:s) {
    //         cout<<a<<' ';
    //     }
    //     cout<<'\n';
    // }
    
    return answer;
}