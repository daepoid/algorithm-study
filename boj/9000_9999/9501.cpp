#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(){
  int tc;
  scanf("%d", &tc);
  while(tc-- > 0){
    int n, d;
    int v, f, c;
    int sum = 0;
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n; i++){
      scanf("%d %d %d", &v, &f, &c);
      if (v * f / c >= d){
        sum++;
      }    
    }
    printf("%d\n", sum);
  }
}