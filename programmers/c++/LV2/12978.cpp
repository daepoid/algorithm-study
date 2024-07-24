#include<bits/stdc++.h>
#define MAX 51
#define INF 2100000000
#define pii pair<int, int>
using namespace std;

int board[MAX][MAX];
bool visited[MAX];
int dist[MAX];

void dijkstra(int start, int N) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()) {
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        
        if(visited[curr]) {
            continue;
        }
        
        for(int i = 1; i < N + 1; i++) {
            if(board[curr][i] != 0 && board[curr][i] + cost < dist[i]) {
                dist[i] = cost + board[curr][i];
                pq.push({dist[i], i});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    fill(dist, dist + N + 1, INF);
    
    for(vector<int> r : road) {
        int a = r[0], b = r[1], c = r[2];
        board[a][b] = board[a][b] != 0 ? min(board[a][b], c) : c;
        board[b][a] = board[b][a] != 0 ? min(board[b][a], c) : c;
    }
    
    dijkstra(1, N);
    for(int i = 1; i < N + 1; i++) {
        answer += dist[i] <= K ? 1 : 0;
    }
    return answer;
}