#include <iostream>
#include <stack>
using namespace std;
int arr[1000001];
int nge[1000001];
bool impos;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    stack<int> s;
    int i=1;
    s.push(i);
    //i++;
    for(int i=2;i<=n;i++) {
        impos=false;
        while(!s.empty()) {
            if(arr[i]>arr[s.top()]){
                nge[s.top()]=arr[i];
                s.pop();
            }
            else {
                s.push(i);
                impos=true;
                break;
            }
        
        }
        
        if(!impos) s.push(i);
    }
    
    while(!s.empty()) {
        nge[s.top()]=-1;
        s.pop();
    }
    for(int i=1;i<=n;i++) {
        cout<<nge[i]<<' ';
    }
}