#include <bits/stdc++.h>
#define MAX 5001
#define INF 987654321
using namespace std;

int N, dp[MAX];

int main() {
  int temp1, temp2;
  scanf("%d", &N);
  temp1 = N / 5;
  temp2 = N % 5;
  while (temp1 >= 0) {
    if (temp2 % 3 != 0) {
      temp1--;
      temp2 += 5;
    } else {
      temp2 /= 3;
      printf("%d\n", temp1 + temp2);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}