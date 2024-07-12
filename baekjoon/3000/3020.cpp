//
// Created by SeHyun on 2023-03-03.
//


#include "bits/stdc++.h"

#define MAX 500001
#define ll long long
using namespace std;

int N, H, height;
ll top[MAX], bottom[MAX];
ll cnt, answer = 100000000001;

int main() {
    scanf("%d %d", &N, &H);
    for (int i = 0; i < N; i++) {
        scanf("%d", &height);
        if (i % 2 == 0) {
            bottom[height]++;
        } else {
            top[H - height + 1]++;
        }
    }

    for (int i = 1; i < H + 1; i++) {
        top[i] += top[i - 1];
        bottom[H - i] += bottom[H - i + 1];
    }

    for (int i = 1; i < H + 1; i++) {
        if (top[i] + bottom[i] < answer) {
            cnt = 1;
            answer = top[i] + bottom[i];
        } else if (top[i] + bottom[i] == answer) {
            cnt++;
        }
    }

    printf("%lld %lld", answer, cnt);
}