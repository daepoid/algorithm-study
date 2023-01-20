//
// Created by SeHyun on 2023-01-16.
//


#include "bits/stdc++.h"

#define ll long long
using namespace std;

ll N, P, Q, X, Y;

map<ll, ll> dp;

ll calc(ll n) {
    if (n <= 0) {
        return 1;
    }

    if (dp[n] != 0) {
        return dp[n];
    }

    return dp[n] = calc(n / P - X) + calc(n / Q - Y);
}

int main() {
    scanf("%lld %lld %lld %lld %lld", &N, &P, &Q, &X, &Y);
    ll answer = calc(N);
    printf("%lld\n", answer);
}