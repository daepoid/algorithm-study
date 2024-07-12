#include <bits/stdc++.h>
#define MAX 501
using namespace std;

int N, M;
int board[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int answer = 0;
bool visited[MAX][MAX];

bool is_valid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx < M;
}

void dfs(int y, int x, int cnt, int sum) {
  if (cnt == 3) {
    answer = max(answer, sum);
    return;
  }

  for (int i = 0; i < 4; i++) {
    int newy = y + dy[i];
    int newx = x + dx[i];

    if (!is_valid(newy, newx)) {
      continue;
    }
    if (visited[newy][newx]) {
      continue;
    }
    visited[newy][newx] = true;
    dfs(newy, newx, cnt + 1, sum + board[newy][newx]);
    visited[newy][newx] = false;
  }
}

void non_dfs(int y, int x) {

  // ㅏ
  if (is_valid(y - 1, x) && is_valid(y, x) && is_valid(y, x + 1) &&
      is_valid(y + 1, x)) {
    answer = max(answer, board[y - 1][x] + board[y][x] + board[y][x + 1] +
                             board[y + 1][x]);
  }

  // ㅗ
  if (is_valid(y - 1, x) && is_valid(y, x - 1) && is_valid(y, x) &&
      is_valid(y, x + 1)) {
    answer = max(answer, board[y - 1][x] + board[y][x - 1] + board[y][x] +
                             board[y][x + 1]);
  }

  // ㅓ
  if (is_valid(y - 1, x) && is_valid(y, x - 1) && is_valid(y, x) &&
      is_valid(y + 1, x)) {
    answer = max(answer, board[y - 1][x] + board[y][x - 1] + board[y][x] +
                             board[y + 1][x]);
  }

  // ㅜ
  if (is_valid(y, x - 1) && is_valid(y, x) && is_valid(y, x + 1) &&
      is_valid(y + 1, x)) {
    answer = max(answer, board[y][x - 1] + board[y][x] + board[y][x + 1] +
                             board[y + 1][x]);
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      visited[i][j] = true;
      dfs(i, j, 0, board[i][j]);
      non_dfs(i, j);
      visited[i][j] = false;
    }
  }

  printf("%d\n", answer);
}