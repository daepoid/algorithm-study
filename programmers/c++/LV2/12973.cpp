#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    stack <char> stk;
    for(int i = 0; i < s.length(); i++){
        if(stk.empty()){
            stk.push(s[i]);
        }
        else{
            if(stk.top() == s[i]){
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }
    }
    if(stk.empty()){
        return 1;
    }
    else{
        return 0;
    }   
}