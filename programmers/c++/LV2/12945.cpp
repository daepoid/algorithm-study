#include <bits/stdc++.h>
using namespace std;

long long int dp[100001];

long long int fib(int n){
    if(n < 2){
        return dp[n];
    }
    else{
        if(dp[n] == 0){
            dp[n] = fib(n - 1) + fib(n - 2);
        }
        if(dp[n] > 1234567){
            dp[n] %= 1234567;
        }
        return dp[n];
    }    
}

int solution(int n) {
    int answer = 0;
    dp[1] = 1;
    answer = fib(n) % 1234567;
    return answer;
}

int main () {
    int n = 3;
    long long int result = solution(n);
    cout << result << "\n";
}