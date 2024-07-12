//
// Created by 박세현 on 2023/04/06.
//

#include "bits/stdc++.h"

#define MAX 1001
using namespace std;


int R, C, answer = -1;
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
pair<int, int> pos;
vector<pair<int, int> > fires;
string board[MAX];
int time_board[MAX][MAX];
bool visited[MAX][MAX];

bool is_valid(int newy, int newx) {
    return 0 <= newy && newy < R && 0 <= newx && newx < C;
}

void bfs_fire(pair<int, int> fire) {
    queue<pair<pair<int, int>, int> > q;
    memset(visited, false, sizeof(visited));
    q.push(make_pair(fire, 1));
    visited[fire.first][fire.second] = true;
    time_board[fire.first][fire.second] = 1;

    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int time = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newy = y + dy[i];
            int newx = x + dx[i];

            if (!is_valid(newy, newx)) {
                continue;
            }

            if (visited[newy][newx]) {
                continue;
            }

            if (board[newy][newx] == '#') {
                continue;
            }

            q.push(make_pair(make_pair(newy, newx), time + 1));
            visited[newy][newx] = true;
            time_board[newy][newx] = time_board[newy][newx] == 0 ? time + 1 : min(time_board[newy][newx], time + 1);
        }
    }
}

void bfs() {
    queue<pair<pair<int, int>, int> > q;
    memset(visited, false, sizeof(visited));

    q.push(make_pair(pos, 0));
    visited[pos.first][pos.second] = true;

    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int time = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newy = y + dy[i];
            int newx = x + dx[i];

            if (!is_valid(newy, newx)) {
                answer = time + 1;
                return;
            }

            if (visited[newy][newx]) {
                continue;
            }

            if (board[newy][newx] != '.') {
                continue;
            }

            if (time_board[newy][newx] != 0 && time_board[newy][newx] - 1 <= time + 1) {
                continue;
            }

            q.push(make_pair(make_pair(newy, newx), time + 1));
            visited[newy][newx] = true;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> board[i];
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'J') {
                pos = make_pair(i, j);
            } else if (board[i][j] == 'F') {
                fires.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < fires.size(); i++) {
        bfs_fire(fires[i]);
    }

    bfs();
    if (answer == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << answer << "\n";
    }
}