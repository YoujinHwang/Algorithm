#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;
int arr[50][50];

int solution(vector<string> friends, vector<string> gifts) {
   int size=friends.size();
    for(auto a:gifts) {
        vector<string> names;
        istringstream iss(a);
        string token;
        while(getline(iss,token,' ')) {names.push_back(token);}
        int giver=-1;
        int get=-1;
        for(int i=0;i<size;i++) {
            if(friends[i]==names[0]) {
                giver=i;
            }
            else if(friends[i]==names[1]) get=i;
            if(giver!=-1&&get!=-1) {
                arr[giver][get]++;
                break;
            }
        }
       // cout<<names[0]<<' '<<names[1]<<'\n';
    }
    int answer = 0;
    return answer;
}