#include <bits/stdc++.h>
#define MAX 22
using namespace std;

int R, C, answer = 0;
char board[MAX][MAX];
bool visited[26];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < R && 0 <= newx && newx < C;
}

void dfs(int y, int x, int cnt) {
  answer = max(answer, cnt);
  for (int i = 0; i < 4; i++) {
    int newy = y + dy[i];
    int newx = x + dx[i];
    if (!isvalid(newy, newx)) {
      continue;
    }
    if (visited[board[newy][newx] - 'A']) {
      continue;
    }
    visited[board[newy][newx] - 'A'] = true;
    dfs(newy, newx, cnt + 1);
    visited[board[newy][newx] - 'A'] = false;
  }
}

int main() {
  scanf("%d %d", &R, &C);
  for (int i = 0; i < R; i++) {
    scanf("%s", board[i]);
  }
  visited[board[0][0] - 'A'] = true;
  dfs(0, 0, 1);
  printf("%d\n", answer);
}