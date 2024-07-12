#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, m, tc;
  scanf("%d", &tc);
  while(tc-- > 0){
    scanf("%d %d", &n, &m);
    int count = 0;
    for (int i = 1; i < n - 1; i++) {
      for(int j = i + 1; j < n; j++){
        if((i * i + j * j + m) % (i * j) == 0){
          count++;
        }
      }
    }
    printf("%d\n", count);
  }
}