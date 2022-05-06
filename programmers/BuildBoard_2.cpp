#include "bits/stdc++.h"
#define MAXVAL 0x3f3f3f3f
#define MAX 26
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

int solution(vector<vector<int>> board) {
    int answer = MAXVAL;
    queue<POS>q;
    q.push({ 0, 0, 0, -1 });

    int cost[MAX][MAX][4];

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board.size(); j++) {
            for(int k = 0; k < 4; k++) {
                cost[i][j][k] = MAXVAL;
            }
        }        
    }

    cost[0][0][0] = 0;
    cost[0][0][1] = 0;
    cost[0][0][2] = 0;
    cost[0][0][3] = 0;

    while(!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int c = q.front().cost;
        int dir = q.front().dir;
        q.pop();

        if(y == board.size() - 1 && x == board.size() - 1) {
            answer = min(answer, cost[y][x][0]);
            answer = min(answer, cost[y][x][1]);
            answer = min(answer, cost[y][x][2]);
            answer = min(answer, cost[y][x][3]);
            continue;
        }

        for(int i = 0; i < 4; i++) {
            int newy = y + dy[i];
            int newx = x + dx[i];

            if(is_valid(newy, newx, board.size())) {
                if(board[newy][newx] == 1) {
                    continue;
                }

                int newc = c;
                if (dir == -1 || i == dir) {
                    newc += 100;
                }
                else {
                    newc += 600;
                }

                if(cost[newy][newx][i] >= newc) {
                    cost[newy][newx][i] = newc;
                    q.push({ newy, newx, newc, i });
                }
            }
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> board = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
    int ans = solution(board);
    printf("%d\n", ans);
    return 0;
}