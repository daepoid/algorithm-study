#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
//
// Created by SeHyun on 2022-12-31.
//

#include "bits/stdc++.h"

#define MAX 51
using namespace std;

vector<int> known, party[MAX];
int friendship[MAX];
int answer, N, M, T, temp;


int find_parent(int num) {
    if (friendship[num] == num) {
        return num;
    }
    return friendship[num] = find_parent(friendship[num]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    friendship[b] = a;
}

bool is_same_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    return a == b;
}

int main() {
    scanf("%d %d", &N, &M);
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &temp);
        known.push_back(temp);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d", &T);
        for (int j = 0; j < T; j++) {
            scanf("%d", &temp);
            party[i].push_back(temp);
        }
    }
    answer = M;

    for (int i = 1; i < N + 1; i++) {
        friendship[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a = party[i][0];
        for (int j = 1; j < party[i].size(); j++) {
            int b = party[i][j];
            union_parent(a, b);
        }
    }

    for (int i = 0; i < M; i++) {
        bool flag = true;
        for (int j = 0; j < party[i].size(); j++) {
            if (!flag) {
                break;
            }
            int a = party[i][j];
            for (int k = 0; k < known.size(); k++) {
                int b = known[k];
                if (is_same_parent(a, b)) {
                    flag = false;
                    break;
                }
            }
        }
        if (!flag) {
            answer--;
        }
    }
    printf("%d\n", answer);
}