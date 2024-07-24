#include<bits/stdc++.h>
#define MAX 10000001
using namespace std;

int dp[MAX];

int solution(int x, int y, int n) {
    fill(dp, dp + MAX - 1, MAX);
    dp[x] = 0;
    for(int i = x; i <= y; i++) {
        if(dp[i] == MAX) {
            continue;
        }
        
        if(i + n <= y) {
            dp[i + n] = min(dp[i + n], dp[i] + 1);        
        }
        
        if(i * 2 <= y) {
            dp[i * 2] = min(dp[i * 2], dp[i] + 1);
        }
        
        if(i * 3 <= y)  {
            dp[i * 3] = min(dp[i * 3], dp[i] + 1);
        }   
    }
    
    return dp[y] == MAX ? -1 : dp[y];
}