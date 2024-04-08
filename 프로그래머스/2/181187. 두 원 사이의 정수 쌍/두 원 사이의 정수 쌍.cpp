#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long c2=0,c1=0;
    int y;
    for(int i=-r2;i<=r2;i++) {
        y=sqrt(pow(r2,2)-pow(i,2));
        c2+=y*2+1;
    }
    
    for(int i=-r1+1;i<r1;i++) {
        y=sqrt(pow(r1,2)-pow(i,2));
        if(pow(y,2)+pow(i,2)==pow(r1,2)) y--;
        c1+=y*2+1;
    }
    
    answer=c2-c1;
    return answer;
}
