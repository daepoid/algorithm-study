#include <bits/stdc++.h>
#define MAX 4001
using namespace std;

int dp[MAX][MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string a, b;
  int answer = 0;
  cin >> a >> b;

  for (int i = 1; i < a.length() + 1; i++) {
    for (int j = 1; j < b.length() + 1; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        answer = max(answer, dp[i][j]);
      }
    }
  }
  cout << answer << "\n";
}