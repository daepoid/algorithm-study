#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> stk;
    
    for(int i = numbers.size() - 1; i >= 0; i--) {
        if(stk.empty()) {
            stk.push(numbers[i]);
            answer.push_back(-1);
            continue;
        }
        
        if(stk.top() > numbers[i]) {
            answer.push_back(stk.top());
            stk.push(numbers[i]);
            continue;
        } 
        
        while(!stk.empty() && stk.top() <= numbers[i]) {
            stk.pop();
        }
        
        answer.push_back(stk.empty() ? -1 : stk.top());            
        stk.push(numbers[i]);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}