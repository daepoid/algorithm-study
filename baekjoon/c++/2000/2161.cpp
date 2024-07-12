#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
using namespace std;
queue<int> que;
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    que.push(i);
  }
  while(true){
    printf("%d", que.front());
    que.pop();
    if(!que.empty()){
      que.push(que.front());
      que.pop();
      printf(" ");
    }else {
      printf("\n");
      break;
    }
  }
}