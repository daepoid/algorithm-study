#include<iostream>
using namespace std;

int ans[1000000];

int cal(int n) { 
  if (n < 0) {
    return 0;
  } else if (n == 0) {
    return ans[n];
  } else {
    int temp = n;
    int cnt = 0;
    while (temp > 0) {
      if (temp % 10 == 0) {
        cnt++;
      }
      temp /= 10;
    }
    if (ans[n - 1] != 0) {
      ans[n] = ans[n - 1] + cnt;   
    } else {
      ans[n] = cal(n - 1) + cnt;
    }
    return ans[n];
  }
}

int main() {

  int tc;
  scanf("%d", &tc);
  ans[0] = 1;

  while (tc-- > 0) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", cal(b) - cal(a - 1));
  }
}