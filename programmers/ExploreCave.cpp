#include "bits/stdc++.h"
#define MAX 200011
using namespace std;

int count_arr[MAX];

void bfs() {
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while(!q.empty()) {
        int num = q.front();
        q.pop();

        int cnt = 0;
        for(int i = 0; i < board[num].size(); i++) {
            int idx = board[num][i];
            if(!visited[idx] && visited[restricted[idx]]) {
                visited[idx] = true;
                q.push(idx);
            } else {
                cnt++;
            }
        }
    }
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;

    build_board();

    bfs();

    return answer;
}

int main() {
    int n = 9;
    vector<vector<int>> path = { {0, 1}, {0, 3}, {0, 7}, {8, 1}, {3, 6}, {1, 2}, {4, 7}, {7, 5} };
    vector<vector<int>> order = {{8, 5}, {6, 7}, {4, 1}};
    // vector<vector<int>> path = { {0, 1}, {0, 3}, {0, 7}, {8, 1}, {3, 6}, {1, 2}, {4, 7}, {7, 5} };
    // vector<vector<int>> order = {{4, 1}, {8, 7}, {6, 5}};
    bool ans = solution(n, path, order);
    cout << ans << endl;
    printf("\n");
    return 0;
}