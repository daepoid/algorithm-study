//
// Created by SeHyun on 2023-01-09.
//


#include "bits/stdc++.h"

#define MAX 201
using namespace std;

int N, M;
int root[MAX];
vector<int> route;

int find_root(int num) {
    if (root[num] == num) {
        return num;
    }
    return root[num] = find_root(root[num]);
}

void union_root(int a, int b) {
    a = find_root(a);
    b = find_root(b);

    root[b] = a;
}


int main() {
    scanf("%d", &N);
    scanf("%d", &M);

    for (int i = 1; i < N + 1; i++) {
        root[i] = i;
    }

    int temp;
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            scanf("%d", &temp);
            if (temp == 1) {
                union_root(i, j);
            }
        }
    }
    for (int i = 0; i < M; i++) {
        scanf("%d", &temp);
        route.push_back(temp);
    }
    for (int i = 0; i < route.size() - 1; i++) {
        if (find_root(route[i]) != find_root(route[i + 1])) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}