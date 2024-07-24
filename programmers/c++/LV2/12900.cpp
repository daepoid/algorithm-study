#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int dp[60001];

int cal(int n){
  if(dp[n] != 0){
    return dp[n];
  }
  dp[n] = (cal(n - 1) + cal(n - 2)) % mod;
  return dp[n];
}

int solution(int n) {
  int answer = 0;
  dp[1] = 1;
  dp[2] = 2;
  answer = cal(n) % mod;

  return answer;
}

int main () {
    int n = 4;
    int result = solution(n);
    cout << result << "\n";
}