#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
  string answer = "";
  int ans_len = number.length() - k;
  stack<int> stk;
  for(int i = 0; i < number.length(); i++){
    if(stk.empty()){
      stk.push(number[i]);
      continue;
    }
    while(!stk.empty() && stk.top() < number[i] && k > 0){
      stk.pop();
      k -= 1;
    }
    stk.push(number[i]);
  }
  while(!stk.empty()){
    answer += stk.top();
    stk.pop();
  }
  reverse(answer.begin(), answer.end());
  if(answer.length() > ans_len){
    answer.erase(ans_len, answer.length() - ans_len);
  }
  return answer;
}