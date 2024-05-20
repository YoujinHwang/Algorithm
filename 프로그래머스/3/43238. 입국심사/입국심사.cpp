// #include <string>
// #include <vector>
// #include <algorithm>
// #define X first
// #define Y second

// using namespace std;

// long long solution(int n, vector<int> times) {
//     long long answer = 0;
//     vector<pair<int,int>> v;
//     for(int i=0;i<times.size();i++) {
//         v.push_back({times[i],i});
//     }
//     sort(v.begin(),v.end());
//     for(int i=0;i<n-1;i++) {
//         v[0].X+=times[v[0].Y];
//         sort(v.begin(),v.end());
//     }
//     answer=v[0].X;
//     return answer;
// }

//위 코드는 시간 초과

 #include <string>
 #include <vector>
 #include <algorithm>


 using namespace std;

 long long solution(int n, vector<int> times) {
     long long answer = 0;
     long long left=1;
     long long right=*max_element(times.begin(), times.end()) * (long long)n;
     
     while(left<=right) {
         long long mid=(left+right)/2;
         long long tot=0;
         for(auto time:times) {
             tot+=mid/time;
             if(tot>=n) break;
         }
         if(tot>=n) {
             right=mid-1;
         }
         else {
             left=mid+1;
         }
     }
     answer=right+1;
    return answer;
 }
     