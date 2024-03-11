#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> name2idx;
map<string, int> name2factor;


int arr[50][50];


void init(vector<string> &friends) {
    int idx=0;
    for(string f:friends) {
        name2idx[f]=idx++;
    }
}
bool cmp(int a, int b) {
    return a>b;
}

int solution(vector<string> friends, vector<string> gifts) {
   init(friends);
    vector<int> v(friends.size(),0);
    for(auto gift:gifts) {
        istringstream iss(gift);
        string name, name2;
        iss>>name>>name2;
        name2factor[name]++;
        name2factor[name2]--;
        arr[name2idx[name]][name2idx[name2]]++;
    }
    for(int i=0;i<friends.size();i++) {
        for (int j=i+1;j<friends.size();j++) {
            string name=friends[i];
            string name2=friends[j];
            
            if(arr[i][j]>arr[j][i]) {
                v[i]++;
            }
            else if(arr[i][j]<arr[j][i]) {
                v[j]++;
            }
            else {
                if(name2factor[name]>name2factor[name2]) {
                    v[i]++;
                }
                else if(name2factor[name]<name2factor[name2]) {
                    v[j]++;
                }
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    int answer = 0;
    answer=v[0];
    return answer;
}