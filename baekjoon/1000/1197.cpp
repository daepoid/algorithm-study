//
// Created by SeHyun on 2023-03-02.
//


#include "bits/stdc++.h"

#define MAX 10001
using namespace std;

int V, E, answer;
int parents[MAX];
vector<pair<int, pair<int, int>>> v;

int getParent(int idx) {
    if (parents[idx] == idx) {
        return idx;
    } else {
        return parents[idx] = getParent(parents[idx]);
    }
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a != b) {
        parents[b] = parents[a];
    }
}

int main() {
    scanf("%d %d", &V, &E);
    int a, b, c;
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &a, &b, &c);
        v.push_back({c, {a, b}});
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < V + 1; i++) {
        parents[i] = i;
    }

    for (int i = 0; i < E; i++) {
        if (getParent(v[i].second.first) != getParent(v[i].second.second)) {
            unionParent(v[i].second.first, v[i].second.second);
            answer += v[i].first;
        }
    }

    printf("%d\n", answer);
}