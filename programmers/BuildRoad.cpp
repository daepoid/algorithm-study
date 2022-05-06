#include "bits/stdc++.h"
#define MAX 30
#define MAXVAL 0x3f3f3f3f
using namespace std;

struct POS {
    int y;
    int x;
    int cost;
    int dir;
};

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

bool is_valid(int newy, int newx, int N) {
    return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

int bfs(vector<vector<int>> board) {
    vector<vector<int>> cost;
    cost.resize(board.size(), vector<int>(board.size(), MAXVAL));

    queue<POS> q;
    q.push({0, 0, 0, -1});
    cost[0][0] = 0;

    int answer = MAXVAL;
    while(!q.empty()) {

        int y = q.front().y;
        int x = q.front().x;
        int pay = q.front().cost;
        int dir = q.front().dir;
        q.pop();

        if(y == board.size() - 1 && x == board.size() - 1) {
            answer = min(answer, cost[y][x]);
            continue;
        }

        for(int i = 0; i < 4; i++) {
            int newy = y + dy[i];
            int newx = x + dx[i];

            if(is_valid(newy, newx, board.size())) {
                if(board[newy][newx] == 1) {
                    continue;
                }

                int new_pay;
                if(dir == -1 || dir == i) {
                    new_pay = pay + 100;
                } else {
                    new_pay = pay + 600;
                }

                if(cost[newy][newx] >= new_pay) {
                    cost[newy][newx] = new_pay;
                    q.push({newy, newx, new_pay, i});
                }
            }            
        }
    }
    return answer;
}

int solution(vector<vector<int>> board) {
    return bfs(board);
}

int main() {
    vector<vector<int>> board = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
    int ans = solution(board);
    printf("%d\n", ans);
    return 0;
}