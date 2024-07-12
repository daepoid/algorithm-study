#include "bits/stdc++.h"
#define MAX 1001
#define INF 0x3f3f3f3f
using namespace std;

int N, M;
int start, dest;
// vector<pair<int, int>> v[MAX];
int board[MAX][MAX];
int dist[MAX];

void solution() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        for(int i = 1; i <= N; i++) {

            if(board[curr][i] == INF) {
                continue;
            }

            int next = i;
            int next_cost = board[curr][next];

            if(dist[next] > cost + next_cost) {
                dist[next] = cost + next_cost;
                pq.push({ dist[next], next });
            }
        }

    }
    printf("%d\n", dist[dest]);
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            board[i][j] = INF;
        }
    }

    for(int i = 0 ; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(board[a][b] > c) {
            board[a][b] = c;
        }
    }

    for(int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    scanf("%d %d", &start, &dest);

    solution();
}
