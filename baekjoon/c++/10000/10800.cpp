//
// Created by SeHyun on 2023-03-03.
//


#include "bits/stdc++.h"

#define MAX 200001
using namespace std;

int N;
int C[MAX], S[MAX], answer[MAX];
vector<pair<pair<int, int>, int>> v;

int main() {
    scanf("%d", &N);

    int c, s;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &c, &s);
        v.push_back({{s, c}, i});
    }

    sort(v.begin(), v.end());

    int sum = 0;
    int color = -1;
    int weight = 0;

    for (int i = 0; i < N; i++) {
        weight = v[i].first.first;
        S[weight] += weight;

        color = v[i].first.second;
        C[color] += weight;

        sum += weight;

        answer[v[i].second] = sum - C[color] - S[weight] + weight;
        if (v[i - 1].first.first == v[i].first.first && v[i - 1].first.second == v[i].first.second) {
            answer[v[i].second] = answer[v[i - 1].second];
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", answer[i]);
    }
}