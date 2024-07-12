#include <bits/stdc++.h>
using namespace std;

char board[51][51];
int dy[6] = {0, -1, -1, 0, 1, 1};
int dx[6] = {1, 1, 0, -1, -1, 0};
int n, visited[51][51], ans = 0;
int check[51][51];
bool flag = false;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < n && 0 <= newx && newx < n;
}

void check_around(int y, int x) {
  int temp_cnt = 0;
  for (int i = 0; i < 7; i++) {
    int newy = y + dy[i % 6];
    int newx = x + dx[i % 6];

    if (isvalid(newy, newx) && board[newy][newx] == 'X') {
      temp_cnt++;
      if (temp_cnt > 1) {
        break;
      }
    } else {
      temp_cnt = 0;
    }
  }
  ans = max(ans, temp_cnt + 1);
}

void dfs(int y, int x, int cnt) {
  // 처음 입장
  ans = max(ans, 1);
  visited[y][x] = cnt;
  check_around(y, x);
  for (int i = 0; i < 6; i++) {
    int newy = y + dy[i];
    int newx = x + dx[i];
    if (!isvalid(newy, newx) || board[newy][newx] == '-' ||
        visited[newy][newx] != -1) {
      continue;
    }
    dfs(newy, newx, 1 - cnt);
    // 두 개가 붙어있음
    ans = max(ans, 2);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", board[i]);
  }
  memset(visited, -1, sizeof(visited));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 'X' && visited[i][j] == -1) {
        dfs(i, j, 0);
      }
    }
  }
  printf("%d\n", ans);
}