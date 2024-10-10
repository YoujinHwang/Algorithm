#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<int,int> giftIndex; //선물지수
vector<int> giftNum; //받는 선물 개수
int arr[50][50];
unordered_map<string,int> FtoI; //이름과 인덱스 매칭


int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int n=friends.size();
    int ind=0;
    for(auto s:friends) {
        FtoI[s]=ind;
        giftIndex[ind]=0;
        ind++;
    }
    for(auto s:gifts) {
        auto it=s.find(' ');
        string giver=s.substr(0,it);
        string receiver=s.substr(it+1);
        //cout<<giver<<' '<<receiver<<'\n';
        int x=FtoI[giver];
        int y=FtoI[receiver];
        arr[x][y]++;
        giftIndex[x]++;
        giftIndex[y]--;
    }
    for(int i=0;i<n;i++) {
        int cnt=0;
        for(int j=0;j<n;j++) {
            if(i==j) continue;
            if(arr[i][j]>arr[j][i]) {
                cnt++;
            }
            else if(arr[i][j]==arr[j][i]) {
                if(giftIndex[i]>giftIndex[j]) {
                    cnt++;
                }
            }
        }
        giftNum.push_back(cnt);
    }
    sort(giftNum.begin(),giftNum.end(),greater());
    answer=giftNum[0];
    return answer;
}