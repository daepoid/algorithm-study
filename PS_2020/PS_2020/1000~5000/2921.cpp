#include<iostream>
using namespace std;

int main() {

  int n;
  long long int ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    ans += (i * (i + 1) / 2 * 3);
  }
  printf("%lld", ans);
}