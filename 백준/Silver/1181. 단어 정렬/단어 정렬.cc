#include <bits/stdc++.h>
using namespace std;

bool cmp (string name1, string name2) {
        if(name1.size()==name2.size()) {
            return name1<name2;
        }
        return name1.size()<name2.size();
    }
string words[20000];
int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        string word;
        cin>>word;
        words[i]=word;
    }
    sort(words,words+n,cmp);
    for(int i=0;i<n;i++) {
        if(words[i]==words[i-1]) continue;
        cout<<words[i]<<'\n';
    }
}