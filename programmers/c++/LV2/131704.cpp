#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> order) {
    deque<int> q;
    stack<int> stk, sub;
    for(int i = 0; i < order.size(); i++) {
        q.push_back(i + 1);
    }
    
    while(true) {
        int idx = stk.size();
        if(!q.empty() && q.front() == order[idx]) {
            stk.push(q.front());
            q.pop_front();
            continue;
        }
        
        if(!sub.empty() && sub.top() == order[idx]) {
            stk.push(sub.top());
            sub.pop();
            continue;
        }
        
        if(!q.empty()) {
            sub.push(q.front());
            q.pop_front();
        } else {
            break;
        }
    }
    return stk.size();
}