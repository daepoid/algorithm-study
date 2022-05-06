#include "bits/stdc++.h"
#define MAX 1001
#define INF 0x3f3f3f3f
using namespace std;

int N, M, X;
int dist[MAX];
int answer[MAX];
vector<pair<int, int>> v[MAX];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        for(int i = 0; i < v[curr].size(); i++) {
            int next = v[curr][i].first;
            int next_cost = v[curr][i].second;

            if(dist[next] > cost + next_cost) {
                dist[next] = cost + next_cost;
                pq.push({ -dist[next], next });
            }
        }
    }
}

void initDist() {
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &X);
    
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({ b, c });
    }

    for(int i = 1; i <= N; i++) {
        initDist();
        dijkstra(i);
        answer[i] = dist[X];
    }

    initDist();
    dijkstra(X);

    for(int i = 1; i <= N; i++) {
        answer[i] += dist[i];
        answer[0] = max(answer[0], answer[i]);
    }
    printf("%d\n", answer[0]);
}
