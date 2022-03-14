#include <bits/stdc++.h>
#define MAX 22
using namespace std;

int R, C, answer = 0;
char board[MAX][MAX];
bool visited_alpha[26];
bool visited[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < R && 0 <= newx && newx < C;
}

void dfs(int y, int x, int cnt) {
  int c_num = board[y][x] - 'A';
  if (visited_alpha[c_num]) {
    answer = max(answer, cnt);
    return;
  }
  visited_alpha[c_num] = true;
  cnt++;

  for (int i = 0; i < 4; i++) {
    int newy = y + dy[i];
    int newx = x + dx[i];
    if (!isvalid(newy, newx)) {
      continue;
    }
    if (visited[newy][newx]) {
      continue;
    }
    visited[newy][newx] = true;
    dfs(newy, newx, cnt);
    visited[newy][newx] = false;
  }
}

int main() {
  scanf("%d %d", &R, &C);
  for (int i = 0; i < R; i++) {
    scanf("%s", board[i]);
  }
  dfs(0, 0, 0);
  printf("%d\n", answer);
}