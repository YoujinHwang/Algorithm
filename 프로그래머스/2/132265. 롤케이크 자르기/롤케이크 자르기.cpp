#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int num=*max_element(topping.begin(),topping.end());
    // int arr[num+1]={0,};
    map<int,int> m;
    for(auto s:topping) {
        if(m.find(s)!=m.end()) {
            m[s]++;
        }
        else {
            m[s]=1;
        }
    }
    //int x=*max_element(topping.begin(), topping.end());
    //cout<<x;
    set<int> type;
    for(auto s:topping) {
        type.insert(s);
        m[s]--;
        if(m[s]==0) {
            m.erase(s);
        }
        if(type.size()==m.size()) {
            answer++;
        }
        
    }
    return answer;
}