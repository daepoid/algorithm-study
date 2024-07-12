#include <bits/stdc++.h>
#define MAX 20001
#define INF 2100000000
using namespace std;

int V, E, K;
int answer[MAX];
vector<pair<int, int>>nodes[MAX];

void solutions() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, K});
    answer[K] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int num = pq.top().second;
        pq.pop();

        for(int i = 0; i < nodes[num].size(); i++) {
            int next = nodes[num][i].first;
            int next_cost = nodes[num][i].second;

            if(answer[next] > cost + next_cost) {
                answer[next] = cost + next_cost;
                pq.push({-answer[next], next});
            }
        }        
    }

    for(int i = 1; i <= V; i++) {
        if(answer[i] == INF) {
            printf("INF\n");
        } else {
            printf("%d\n", answer[i]);
        }
    }
}

int main() {
    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    for(int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        nodes[u].push_back({v, w});
    }
    for(int i = 1; i <= V; i++) {
        answer[i] = INF;
    }
    solutions();
}