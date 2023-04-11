//
// Created by 박세현 on 2023/04/08.
//


#include "bits/stdc++.h"

using namespace std;

int N, P, D, answer = 0;
vector<pair<int, int> > v;
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &P, &D);
        v.push_back(make_pair(D, P));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        pq.push(v[i].second);
        if (v[i].first < pq.size()) {
            pq.pop();
        }
    }

    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }

    cout << answer << "\n";
}