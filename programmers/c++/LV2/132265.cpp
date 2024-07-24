#include<bits/stdc++.h>
using namespace std;

map<int, int> ob, yb;

int solution(vector<int> topping) {
    int answer = 0;
    for(int i = 0; i < topping.size(); i++) {
        ob[topping[i]]++;
    }
    
    for(int i = topping.size() - 1; i >= 0; i--) {
        yb[topping[i]]++;
        ob[topping[i]]--;
        if(ob[topping[i]] == 0) {
            ob.erase(topping[i]);
        }
        
        if(yb.size() == ob.size()) {
            answer++;
        }
    }
    
    return answer;
}