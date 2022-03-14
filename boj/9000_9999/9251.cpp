#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int dp[MAX][MAX];
string str_dp[MAX][MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string a, b;
  cin >> a >> b;

  for (int i = 1; i < a.length() + 1; i++) {
    for (int j = 1; j < b.length() + 1; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        str_dp[i][j] = str_dp[i - 1][j - 1] + a[i - 1];
      } else {
        if (dp[i - 1][j] > dp[i][j - 1]) {
          dp[i][j] = dp[i - 1][j];
          str_dp[i][j] = str_dp[i - 1][j];
        } else {
          dp[i][j] = dp[i][j - 1];
          str_dp[i][j] = str_dp[i][j - 1];
        }
      }
    }
  }
  cout << dp[a.length()][b.length()] << "\n";
  cout << str_dp[a.length()][b.length()] << "\n";
}