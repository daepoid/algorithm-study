#include <bits/stdc++.h>
#define MAX 22
using namespace std;

int R, C, K, W;
int board[MAX][MAX];
bool walls[MAX][MAX][4];
int wdx[4][3] = { {-1, 0, 1}, {-1, 0, 1}, {-1, -1, -1}, {1, 1, 1} };
int wdy[4][3] = { {1, 1, 1}, {-1, -1, -1}, {-1, 0, 1}, {-1, 0, 1} };

// 우, 좌, 상, 하
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

struct Heater {
    int x;
    int y;
    int dir;
};

vector<Heater> heaters;
vector<pair<int, int>> check_pos;

bool isValid(int x, int y) {
    return 0 < x && x <= R && 0 < y && y <= C;
}

bool isWalls(int x, int y, int dir, int idx) {
    if(idx == 1) { // 정방향
        if(walls[x][y][dir]) {
            return true;
        }
    } else if(idx == 0) { // 정방향의 위 또는 왼쪽 부분
        switch(dir) {
        case 0:
            return walls[x][y][2] || walls[x - 1][y][dir];
        case 1:
            return walls[x][y][2] || walls[x - 1][y][dir];
        case 2:
            return walls[x][y][1] || walls[x][y - 1][dir];
        case 3:
            return walls[x][y][1] || walls[x][y - 1][dir];
        }
    } else if(idx == 2) { // 정방향의 아래 또는 오른쪽 부분
        switch (dir) {
        case 0:
            return walls[x][y][3] || walls[x + 1][y][dir];
        case 1:
            return walls[x][y][3] || walls[x + 1][y][dir];
        case 2:
            return walls[x][y][0] || walls[x][y + 1][dir];
        case 3:
            return walls[x][y][0] || walls[x][y + 1][dir];
        }
    }
    return false;
}

void spreadWind(int ori_x, int ori_y, int dir) {
    bool visited[MAX][MAX] = {
        false,
    };

    queue<pair<pair<int, int>, int>> q;
    q.push({{ori_x, ori_y}, 5});
    visited[ori_x][ori_y] = true;
    
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int temperature = q.front().second;
        q.pop();

        board[x][y] += temperature;

        if(temperature == 1) {
            continue;
        }

        for(int i = 0; i < 3; i++) {
            int newx = x + wdx[dir][i];
            int newy = y + wdy[dir][i];
            if(isValid(newx, newy) && !isWalls(x, y, dir, i) && !visited[newx][newy]) {
                visited[newx][newy] = true;
                q.push({{newx, newy}, temperature - 1});
            }
        }
    }    
}

void changeTemperature() {
    int weight[MAX][MAX] = {
        0,
    };

    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            // 오른쪽
            if(j + 1 <= C && !walls[i][j][0]) {
                int val = abs(board[i][j] - board[i][j + 1]) / 4;
                if(board[i][j] > board[i][j + 1]) {
                    weight[i][j] -= val;
                    weight[i][j + 1] += val;                    
                } else if(board[i][j] < board[i][j + 1]) {
                    weight[i][j] += val;
                    weight[i][j + 1] -= val;
                }
            }

            // 아래
            if (i + 1 <= R && !walls[i][j][3]) {
                int val = abs(board[i][j] - board[i + 1][j]) / 4;
                if (board[i][j] > board[i + 1][j]) {
                    weight[i][j] -= val;
                    weight[i + 1][j] += val;
                }
                else if (board[i][j] < board[i + 1][j]) {
                    weight[i][j] += val;
                    weight[i + 1][j] -= val;
                }
            }
        }
    }

    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            board[i][j] += weight[i][j];
        }
    }    
}


void reduceTemperature() {
    for(int i = 1; i <= C; i++) {
        board[1][i] = max(board[1][i] - 1, 0);
        board[R][i] = max(board[R][i] - 1, 0);
    }

    for(int i = 2 ; i < R; i++) {
        board[i][1] = max(board[i][1] - 1, 0);
        board[i][C] = max(board[i][C] - 1, 0);
    }
}

bool validTemperature() {
    for(int i = 0; i < check_pos.size(); i++) {
        if(board[check_pos[i].first][check_pos[i].second] < K) {
            return false;
        }
    }
    return true;
}

void printBoard() {
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    scanf("%d %d %d", &R, &C, &K);
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            int temp;
            scanf("%d", &temp);
            if(0 < temp && temp < 5) {
                heaters.push_back({i, j, temp - 1});
            } else if(temp == 5) {
                check_pos.push_back({i, j});
            }
        }
    }

    scanf("%d", &W);
    for(int i = 0; i < W; i++) {
        int x, y, chk;
        scanf("%d %d %d", &x, &y, &chk);
        if(chk == 0) {
            walls[x][y][2] = true;
            walls[x - 1][y][3] = true;
        } else if(chk == 1) {
            walls[x][y][0] = true;
            walls[x][y + 1][1] = true;
        }
    }

    int chocolate = 0;
    while(chocolate < 101) {
        for(int i = 0; i < heaters.size(); i++) {
            spreadWind(heaters[i].x + dx[heaters[i].dir], heaters[i].y + dy[heaters[i].dir], heaters[i].dir);
        }
        changeTemperature();
        reduceTemperature();
        chocolate++;
        if(validTemperature()) {
            break;
        }
    }
    printf("%d\n", chocolate);
}