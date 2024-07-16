#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int,int> m;
    for(auto num:nums) {
        if(m.find(num)==m.end()) {
            m.insert({num,1});
        }
        else m[num]++;
    }
    // cout<<m.size();
    int cnt=nums.size()/2;
    if(m.size()<=cnt) {
        answer=m.size();
    }
    else {
        answer=cnt;
    }
    return answer;
}