#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int rec(int a, int b){
  if(b == 1){
    return 1;
  }
  if(a == 0){
    return b;
  }
  return rec(a - 1, b) + rec(a, b - 1);
}


int main() {
  int tc;
  scanf("%d", &tc);
  while(tc-- >0){
    int k, n;
    scanf("%d %d", &k, &n);
    printf("%d\n", rec(k, n));  
  }
}