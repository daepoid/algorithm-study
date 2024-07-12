//
// Created by SeHyun on 2023-01-08.
//
#include "bits/stdc++.h"

#define MAX 1000001
using namespace std;

int N, M, temp;
int friendship[MAX];

int find_root(int num) {
    if (friendship[num] == num) {
        return num;
    } else {
        return friendship[num] = find_root(friendship[num]);
    }
}

void union_root(int a, int b) {
    a = find_root(a);
    b = find_root(b);

    friendship[b] = a;
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 1; i < N + 1; i++) {
        friendship[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &c, &a, &b);
        if (c == 0) {
            union_root(a, b);
        } else if (c == 1) {
            printf("%s\n", find_root(a) == find_root(b) ? "YES" : "NO");
        }
    }
}