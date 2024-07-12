#include <bits/stdc++.h>
#define MAX 4
using namespace std;

int M, S;
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int sdx[4] = {-1, 0, 1, 0};
int sdy[4] = {0, -1, 0, 1};
int smell[MAX][MAX] = {};
int best_move[4] = {};
int temp_move[4] = {};
int nowMax = -1;

struct Fish {
    int x;
    int y;
    int dir;
};

vector<Fish> board[MAX][MAX];
vector<Fish> copied_board[MAX][MAX];

Fish shark = {-1, -1, -1};

void copyFishes() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            copied_board[i][j] = board[i][j];
        }
    }        
}

bool isValid(int x, int y) {
    return 0 <= x && x < MAX && 0 <= y && y < MAX;
}

bool isBlood(int x, int y) {
    return smell[x][y] > 0;
}

bool isShark(int x, int y) {
    return x == shark.x && y == shark.y;
}

void moveFishes() {
    vector<Fish> temp_fishes[MAX][MAX];
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            for(int k = 0; k < board[i][j].size(); k++) {

                Fish fish = board[i][j][k];

                for(int a = 0; a < 8; a++) {
                    int dir = (fish.dir - a + 8) % 8;
                    int newx = fish.x + dx[dir];
                    int newy = fish.y + dy[dir];
                    if(isValid(newx, newy) && !isBlood(newx, newy) && !isShark(newx, newy)) {
                        fish = {newx, newy, dir};
                        break;
                    }
                }
                temp_fishes[fish.x][fish.y].push_back(fish);
            }
        }        
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            board[i][j] = temp_fishes[i][j];
        }
    }
}

int countEatFishes() {
    bool visited[MAX][MAX] = {
        false,
    };

    int x = shark.x;
    int y = shark.y;
    int cnt = 0;

    for(int i = 0; i < 3; i++) {
        int dir = temp_move[i];
        int newx = x + sdx[dir];
        int newy = y + sdy[dir];
        if(!isValid(newx, newy)) {
            return -1;
        }

        if(!visited[newx][newy]) {
            visited[newx][newy] = true;
            cnt += board[newx][newy].size();
        }
        x = newx;
        y = newy;
    }
    return cnt;
}


void findSharkRoute(int cnt) {
    if (cnt == 3) {
        int eatCount = countEatFishes();
        if (eatCount > nowMax) {
            for (int i = 0; i < 3; i++) {
                best_move[i] = temp_move[i];
            }
            nowMax = eatCount;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        temp_move[cnt] = i;
        findSharkRoute(cnt + 1);
    }
}


void eatFishes() {
    int x = shark.x;
    int y = shark.y;
    for (int i = 0; i < 3; i++) {
        int dir = best_move[i];
        shark.x += sdx[dir];
        shark.y += sdy[dir];
        if(board[shark.x][shark.y].size() != 0) {
            board[shark.x][shark.y].clear();
            smell[shark.x][shark.y] = 3;
        }
    }
}

void moveShark() {
    nowMax = -1;
    findSharkRoute(0);
    eatFishes();
}

void reduceSmell() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            smell[i][j] = max(smell[i][j] - 1, 0);
        }
    }    
}

void pasteFishes() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            for(int k = 0; k < copied_board[i][j].size(); k++) {
                board[i][j].push_back(copied_board[i][j][k]);
            }
        }
    }    
}

int main() {
    scanf("%d %d", &M, &S);

    int x, y, d;
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &x, &y, &d);
        board[x - 1][y - 1].push_back({ x - 1, y - 1, d - 1 });
    }

    scanf("%d %d", &x, &y);
    shark.x = x - 1;
    shark.y = y - 1;

    for(int i = 0; i < S; i++) {
        copyFishes();
        moveFishes();
        moveShark();
        reduceSmell();
        pasteFishes();
    }

    int answer = 0;
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            answer += board[i][j].size();
        }
    }
    printf("%d\n", answer);

    return 0;
}