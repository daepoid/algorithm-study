//
// Created by 박세현 on 2023/04/09.
//


#include "bits/stdc++.h"

#define MAX 20001
#define INF 0x3f3f3f3f
using namespace std;

int V, E, K, u, v, w;
int dist[MAX];
bool visited[MAX];
vector<pair<int, int> > board[MAX];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

int main() {
    scanf("%d %d", &V, &E);
    scanf("%d", &K);

    fill(dist, dist + MAX, INF);
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        board[u].push_back(make_pair(v, w));
    }

    pq.push(make_pair(0, K));
    dist[K] = 0;
    while (!pq.empty()) {
        int now = pq.top().second;
        int now_dist = pq.top().first;
        pq.pop();

        for (int i = 0; i < board[now].size(); i++) {
            int next = board[now][i].first;
            int cost = board[now][i].second;

            if (now_dist + cost < dist[next]) {
                dist[next] = now_dist + cost;
                pq.push(make_pair(dist[next], next));
            }
        }
    }

    for (int i = 1; i < V + 1; i++) {
        if (dist[i] == INF) {
            printf("INF\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }
}