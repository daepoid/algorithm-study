//
// Created by SeHyun on 2023-01-13.
//


#include "bits/stdc++.h"

using namespace std;

int N, S;
vector<int> v;
map<int, int> sums;
long long int answer = 0;

void left_sum(int start, int temp_sum) {
    if (start == N / 2) {
        sums[temp_sum]++;
        return;
    }

    left_sum(start + 1, temp_sum + v[start]);
    left_sum(start + 1, temp_sum);
}

void right_sum(int start, int temp_sum) {
    if (start == N) {
        answer += sums[S - temp_sum];
        return;
    }

    right_sum(start + 1, temp_sum + v[start]);
    right_sum(start + 1, temp_sum);
}

int main() {
    scanf("%d %d", &N, &S);
    v.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    left_sum(0, 0);
    right_sum(N / 2, 0);

    if (S == 0) {
        printf("%lld\n", answer - 1);
    } else {
        printf("%lld\n", answer);
    }
}