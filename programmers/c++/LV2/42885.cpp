#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
  int answer = 0;
  sort(people.begin(), people.end());
  int i = 0, j = people.size() - 1;
  while(i < j){
    if(people[j] + people[i] <= limit){
      i++;
      j--;
      answer++;
    }
    else{
      j--;
      answer++;
    }
  }
  if(i == j){
    answer++;
  }
  return answer;
}