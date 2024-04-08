#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
void dfs(int diceNum, vector<int>& tempContainer,vector<vector<int>>& diceCases, int idx) {
    if(tempContainer.size()==diceNum/2) {
        diceCases.emplace_back(tempContainer);
        return;
    }
    for(int i=idx;i<diceNum;i++) {
        tempContainer.emplace_back(i);
        dfs(diceNum, tempContainer,diceCases,i+1);
        tempContainer.pop_back();
    }
}

void getSum(vector<int>& sums, vector<int>& diceCase, int& sum, vector<vector<int>>& dice, int idx) {
    if(idx==diceCase.size()) {
        sums.emplace_back(sum);
        return;
    }
    for(int i=0;i<dice[diceCase[idx]].size();i++) {
        sum+=dice[diceCase[idx]][i];
        getSum(sums,diceCase,sum,dice,idx+1);
        sum-=dice[diceCase[idx]][i];
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    vector<vector<int>> diceCases;
    vector<int> tempContainer;
    
    dfs(dice.size(),tempContainer,diceCases,0);
    int count =0;
    int max=-1;
    
    while(count<diceCases.size()) {
        vector<int> sumsA, sumsB;
        int sumA=0;
        int sumB=0;
        getSum(sumsA,diceCases[count],sumA,dice,0); 
        getSum(sumsB,diceCases[diceCases.size()-1-count],sumB,dice,0);
        
        sort(sumsA.begin(),sumsA.end());
        sort(sumsB.begin(),sumsB.end());
        
        int total=0;
        for(int i=0;i<sumsA.size();i++) {
            int left=0;
            int right=sumsB.size()-1;
            
            while(left<=right) {
                int mid=(left+right)/2;
                if(sumsA[i]>sumsB[mid]) {
                    left=mid+1;
                }
                else {
                    right=mid-1;
                }
            }
            total+=left;
        }
        if(total>max) {
            max=total;
            answer=diceCases[count];
        }
        count++;
    }
    for(int i=0;i<answer.size();i++) 
        answer[i]++;
  
    return answer;
}