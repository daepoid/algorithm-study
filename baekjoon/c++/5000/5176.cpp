#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int check[501];

int main() {

  int tc, n, count, temp;
  scanf("%d", &tc);
  while (tc-- > 0) {
    int ans = 0;
    memset(check, 0, sizeof(check));
    scanf("%d %d", &n, &count);
    for (int i = 0; i < n; i++) {
      scanf("%d", &temp);
      if (check[temp] == 0) {
        check[temp] = 1;
      } else {
        ans++;
      }
    }    
    printf("%d\n", ans);
  }
}