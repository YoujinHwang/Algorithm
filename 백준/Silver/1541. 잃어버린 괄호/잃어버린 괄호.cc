#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    cin>>input;
    int res=0;
    string num;
    bool isMinus=false;
    for (int i=0;i<=input.size();i++) {
        
        if(input[i]=='-'||input[i]=='+'||i==input.size()) {
            
            if(isMinus) {
                res-=stoi(num);
                num="";
            }
            else {
                res+=stoi(num);
                num="";
            }
        }
            
        else {
            num+=input[i];
        }
        if(input[i]=='-') isMinus=true;
        
    }
    cout<<res;
}