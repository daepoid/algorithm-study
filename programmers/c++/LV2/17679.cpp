#include <bits/stdc++.h>

#define MAX 31
using namespace std;

vector<string> game_board;
bool checked[MAX][MAX];
int answer = 0;

bool is_square(int y, int x) {
    return game_board[y][x] != '.' && game_board[y][x] == game_board[y][x + 1] &&
           game_board[y][x] == game_board[y + 1][x] &&
           game_board[y][x] == game_board[y + 1][x + 1];
}

bool delete_board(int M, int N) {
    bool flag = false;
    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (is_square(i, j)) {
                checked[i][j] = checked[i][j + 1] = checked[i + 1][j] = checked[i + 1][j + 1] = true;
                flag = true;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (checked[i][j]) {
                game_board[i][j] = '.';
                answer++;
            }
        }
    }

    for (int j = 0; j < N; j++) {
        queue<char> q;
        for (int i = M - 1; i >= 0; i--) {
            if (game_board[i][j] != '.') {
                q.push(game_board[i][j]);
            }
        }
        int i = M - 1;
        while (!q.empty()) {
            char ch = q.front();
            q.pop();
            game_board[i--][j] = ch;
        }
        while (i >= 0) {
            game_board[i--][j] = '.';
        }
    }
    return flag;
}

int solution(int m, int n, vector<string> board) {
    game_board = board;
    while (delete_board(m, n)) {
        memset(checked, false, sizeof(checked));
    }
    return answer;
}