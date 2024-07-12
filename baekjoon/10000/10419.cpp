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

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc-- > 0){
    int d;
    scanf("%d", &d);
    int t = (sqrt(1 + 4 * d) - 1) / 2;
    printf("%d\n", t);  
  }
}