#include "bits/stdc++.h"
#define MAX 1011
#define FORWARD true
#define BACKWARD false
using namespace std;

vector<int> f[MAX], b[MAX];
int board[MAX][MAX];
bool trap_list[MAX];

struct node{
    int num;
    int cnt;
    bool status;
};

void init(vector<vector<int>> roads, vector<int> traps) {
    for(int i = 0; i < roads.size(); i++) {
        board[roads[i][0]][roads[i][1]] = roads[i][2];
    }

    for(int i = 0; i < traps.size(); i++) {
        trap_list[traps[i]] = true;
    }
}

int dijkstra(int n, int start, int end) {
    priority_queue<node> pq;
    pq.push({ start , 0, false });


    while (!pq.empty()) {
        int curr = pq.top().num;
        int cost = pq.top().cnt;
        int status = pq.top().status;
        pq.pop();

        for(int i = 0; i < ; i++) {
            
        }
    }
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    init(roads, traps);
    return dijkstra(n, start, end);
}

int main() {
    int n = 4;
    int start = 1;
    int end = 4;
    vector<vector<int>> roads = {{1, 2, 1}, {3, 2, 1}, {2, 4, 1}};
    vector<int> traps = {2, 3};

    int ans = solution(n, start, end, roads, traps);
    printf("%d\n", ans);
    return 0;
}