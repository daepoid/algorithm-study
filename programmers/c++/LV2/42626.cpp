#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(int i = 0; i < scoville.size(); i++){
      min_heap.push(scoville[i]);
    }
    while(min_heap.top() < K && min_heap.size() >= 2){
      answer++;
      int a = min_heap.top();
      min_heap.pop();
      int b = min_heap.top();
      min_heap.pop();
      min_heap.push(a + b * 2);
    }
    if(min_heap.top() < K){
      return -1;
    }
    return answer;
}