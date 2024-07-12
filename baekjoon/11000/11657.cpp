//
// Created by 박세현 on 2023/04/09.
//


#include "bits/stdc++.h"

#define MAX 501
#define INF 0x3f3f3f3f
using namespace std;

int N, M;
int from, to, cost;
int dist[MAX];
vector<pair<pair<int, int>, int> > edges;

int main() {
    scanf("%d %d", &N, &M);
    fill(dist, dist + MAX, INF);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &from, &to, &cost);
        edges.push_back(make_pair(make_pair(from, to), cost));
    }

    dist[1] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < edges.size(); j++) {
            from = edges[j].first.first;
            to = edges[j].first.second;
            cost = edges[j].second;

            if (dist[from] == INF) {
                continue;
            }

            if (dist[from] + cost < dist[to]) {
                dist[to] = dist[from] + cost;
            }
        }
    }

    for (int i = 0; i < edges.size(); i++) {
        from = edges[i].first.first;
        to = edges[i].first.second;
        cost = edges[i].second;

        if (dist[from] == INF) {
            continue;
        }

        if (dist[from] + cost < dist[to]) {
            printf("-1\n");
            return 0;
        }
    }

    for (int i = 2; i < N + 1; i++) {
        if (dist[i] == INF) {
            printf("-1\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }
}