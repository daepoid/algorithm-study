#include<iostream>
using namespace std;

int main() {
  int l, p;
  int ans[5];
  scanf("%d %d", &l, &p);

  for (int i = 0; i < 5; i++) {
    scanf("%d", &ans[i]);
    ans[i] = ans[i] - (l * p);
  }
  for (int i = 0; i < 4; i++) {
    printf("%d ", ans[i]);
  }
  printf("%d\n", ans[4]);
}