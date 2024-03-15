#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int t=bandage[0];
    int x=bandage[1];
    int y=bandage[2];
    int time=0;
    int str=health;
    int t_time=0;
    for(auto s:attacks) {
        while(time<s[0]){
            time++;
            str+=x;
            t_time++;
            if(t_time==t) {
                str+=y;
                t_time=0;
            }
            if(str>health) str=health;
            
        }
        str-=s[1];
        if(str<=0) {
            return -1;
        }
        t_time=0;
        time++;
        cout<<str<<' ';
    }
    answer=str;
    return answer;
}