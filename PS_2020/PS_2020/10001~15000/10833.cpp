#include<iostream>
using namespace std;

int main() {

  int n;
  int a, b;
  int ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    ans += b % a;
  }
  printf("%d\n", ans);
}