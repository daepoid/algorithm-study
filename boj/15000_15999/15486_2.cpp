#include "bits/stdc++.h"
#define MAX 1500011
#define INF 0x3f3f3f3f
using namespace std;

int N;
int T[MAX], P[MAX], dp[MAX];

void solutions() {
    for(int i = 1; i <= N; i++) {
        dp[i] = max(dp[i], dp[i - 1]);

        int idx = i + T[i] - 1;
        if(idx <= N) {
            dp[idx] = max(dp[idx], dp[i - 1] + P[i]);
        }
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d %d", &T[i], &P[i]);
    }
    solutions();
    printf("%d\n", dp[N]);
}
