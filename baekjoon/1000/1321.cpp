//
// Created by SeHyun on 2023-01-12.
//


#include "bits/stdc++.h"

#define MAX 500001

using namespace std;

int N, M;
int troop[MAX];
int sums[MAX];
int arr[MAX];

int main() {
    int weight = 0;
    scanf("%d", &N);
    for (int i = 1; i < N + 1; i++) {
        scanf("%d", &troop[i]);
        sums[i] = sums[i - 1] + troop[i];
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d", &a, &b);
        if (a == 1) {
            scanf("%d", &c);
            arr[b] += c;
        } else if (a == 2) {
            int j;
            weight = 0;
            bool flag = true;
            for (j = 1; j < N + 1; j++) {
                weight += arr[j];
                arr[j] = 0;
                sums[j] += weight;
                if (sums[j] >= b && flag) {
                    printf("%d\n", j);
                    flag = false;
                }
            }
        }
    }
}