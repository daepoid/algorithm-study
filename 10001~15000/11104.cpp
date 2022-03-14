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
  while (tc-- > 0) {
    char str[25];
    int ans = 0;
    scanf("%s", str);
    for(int i = 23; i >= 0; i--){
      ans += (str[i] - '0') * (int)pow(2, 23 - i);
    }
    printf("%d\n", ans);
  }
}