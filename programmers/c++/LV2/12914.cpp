#include <bits/stdc++.h>
using namespace std;
const int mod = 1234567;
int dp[2001];

long long cal(int num){
    if(num < 3){
        return dp[num];
    }
    if(dp[num] == 0){
        dp[num] = cal(num - 1) + cal(num - 2);
        dp[num] %= mod;
    }
    return dp[num];
}

long long solution(int n) {
    long long answer = 0;
    dp[1] = 1;
    dp[2] = 2;
    answer = cal(n) % mod;
    return answer;
}

int main () {
    int n = 4;
    long long result = solution(n);
    cout << result << "\n";
}