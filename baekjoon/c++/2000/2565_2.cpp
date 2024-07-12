#include <bits/stdc++.h>
#define MAX 555
using namespace std;

struct LINE {
  int left;
  int right;
};

int N;
int dp[MAX];
LINE line[MAX];

bool compare(LINE A, LINE B) { return A.left < B.left; }

int main(void) {
  scanf("%d", &N);
  for (int i = 1; i < N + 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    line[i].left = a;
    line[i].right = b;
  }

  int correct = 0;
  sort(line + 1, line + N + 1, compare);
  for (int i = 1; i <= N; i++) {
    dp[i] = 1;
    for (int j = 1; j < i; j++) {
      if (line[i].right > line[j].right) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    correct = max(correct, dp[i]);
  }
  cout << N - correct << endl;
  return 0;
}