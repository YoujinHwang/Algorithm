#include <bits/stdc++.h>
using namespace std;
int heap[100001];
int sz=0;

void push(int x) {
    sz++;
    heap[sz]=x;
    for(int i=sz;i>=2;i/=2) {
        
        if(heap[i/2]>heap[i]) swap(heap[i/2],heap[i]);
        else break;
        
        // if(sz>=2&&sz%2) {
        //     if(heap[sz/2]>heap[sz]) swap(heap[sz/2],heap[sz]);
        // }   
    }
    
}
int top() {
    if(sz)
        return heap[1];
    else return 0;
}

void pop() {
    if(!sz) return;
    swap(heap[1],heap[sz]);
    sz--;
    int i=1;
    while(i*2<=sz) {
        int left=i*2;
        int right=i*2+1;
        int minIdx=i;
        if(left<=sz&&heap[left]<heap[minIdx]) minIdx=left;
        if(right<=sz&&heap[right]<heap[minIdx]) minIdx=right;
        if(minIdx==i) break;
        swap(heap[i],heap[minIdx]);
        i=minIdx;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n;
    while(n--) {
        cin>>x;
        if(x>0) push(x);
        else {
            cout<<top()<<'\n';
            pop();
        }

    }
}