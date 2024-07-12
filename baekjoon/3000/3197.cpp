//
// Created by 박세현 on 2023/04/14.
//


#include "bits/stdc++.h"

#define MAX 1501
using namespace std;

int R, C;
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
string board[MAX];
bool visited[MAX][MAX], visited_swan[MAX][MAX];
deque<pair<int, int> > wq, sq, nw, ns;
bool flag = false;

bool is_valid(int newy, int newx) {
    return 0 <= newy && newy < R && 0 <= newx && newx < C;
}

bool is_connected() {
    while (!sq.empty()) {
        int y = sq.front().first;
        int x = sq.front().second;
        sq.pop_front();

        for (int i = 0; i < 4; i++) {
            int newy = y + dy[i];
            int newx = x + dx[i];

            if (!is_valid(newy, newx)) {
                continue;
            }

            if (visited_swan[newy][newx]) {
                continue;
            }

            visited_swan[newy][newx] = 1;
            if (board[newy][newx] == '.') {
                sq.push_back({newy, newx});
            } else if (board[newy][newx] == 'X') {
                ns.push_back({newy, newx});
            } else if (board[newy][newx] == 'L') {
                return true;
            }
        }
    }
    return false;
}

void bfs() {
    while (!wq.empty()) {
        int y = wq.front().first;
        int x = wq.front().second;
        wq.pop_front();

        for (int i = 0; i < 4; i++) {
            int newy = y + dy[i];
            int newx = x + dx[i];

            if (!is_valid(newy, newx)) {
                continue;
            }

            if (visited[newy][newx]) {
                continue;
            }

            if (board[newy][newx] == 'X') {
                visited[newy][newx] = true;
                nw.push_back({newy, newx});
                board[newy][newx] = '.';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pair<int, int> swan;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> board[i];
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'L') {
                swan = {i, j};
            }

            if (board[i][j] != 'X') {
                visited[i][j] = 1;
                wq.push_back({i, j});
            }
        }
    }

    sq.push_back(swan);
    visited_swan[swan.first][swan.second] = true;

    int turn = 0;
    while (true) {
        if (is_connected()) {
            break;
        }
        bfs();

        wq = nw;
        sq = ns;
        nw.clear();
        ns.clear();
        turn++;
    }
    cout << turn << "\n";
}