#include <bits/stdc++.h>
using namespace std;

int answer = 0;

vector<int> vec;
int tar;

void dfs(int sum, int depth){
  if(depth == vec.size()){
    if(sum == tar){
      answer++;
    }
    return;
  }
  dfs(sum + vec[depth], depth + 1);
  dfs(sum - vec[depth], depth + 1);
}

int solution(vector<int> numbers, int target) {
  vec = numbers;
  tar = target;
  dfs(vec[0], 1);
  dfs(-vec[0], 1);
  return answer;
}