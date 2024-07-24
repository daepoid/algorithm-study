#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    bool chk;
    
    for(int i = 0; i < prices.size(); i++){
        int temp = prices[i];
        chk = false;
        
        for(int j = 1; i + j < prices.size(); j++){
            if(temp > prices[i + j]){
                answer.push_back(j);
                chk = true;
                break;
            }
        }
        
        if(!chk){
            answer.push_back(prices.size() - i - 1);
        }
    }
    return answer;
}