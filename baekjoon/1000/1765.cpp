//
// Created by SeHyun on 2023-01-09.
//


#include "bits/stdc++.h"

#define MAX 1001
using namespace std;

int N, M;
int friendship[MAX];
vector<int> enumy[MAX];

int find_root(int num) {
    if (friendship[num] == num) {
        return num;
    }
    return friendship[num] = find_root(friendship[num]);
}

void union_root(int a, int b) {
    a = find_root(a);
    b = find_root(b);

    friendship[b] = a;
}

int main() {
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 1; i < N + 1; i++) {
        friendship[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        char ch;
        scanf("%c", &ch);
        scanf("%c %d %d", &ch, &a, &b);
        if (ch == 'F') {
            union_root(a, b);
        } else if (ch == 'E') {
            enumy[a].push_back(b);
            enumy[b].push_back(a);
        }
    }

    for (int i = 1; i < N + 1; i++) {
        for (int j = 0; j < enumy[i].size(); j++) {
            for (int k = 0; k < enumy[enumy[i][j]].size(); k++) {
                union_root(i, enumy[enumy[i][j]][k]);
            }
        }
    }


    int answer = 0;
    for (int i = 1; i < N + 1; i++) {
        answer += friendship[i] == i ? 1 : 0;
    }
    printf("%d\n", answer);
}