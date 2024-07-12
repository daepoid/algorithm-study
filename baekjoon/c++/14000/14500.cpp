#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define MAX 501
using namespace std;

int board[MAX][MAX], answer = 0, n, m;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
bool visited[MAX][MAX];

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < n && 0 <= newx && newx < m;
}

void dfs(int y, int x, int sum, int cnt) {
  visited[y][x] = true;
  if (cnt == 3) {
    answer = max(answer, sum);
    return;
  }
  for (int i = 0; i < 4; i++) {
    int newy = y + dy[i];
    int newx = x + dx[i];
    if (isvalid(newy, newx) && !visited[newy][newx]) {
      dfs(newy, newx, sum + board[newy][newx], cnt + 1);
      visited[newy][newx] = false;
    }
  }
}

void other(int y, int x) {
  if (0 < y && 0 < x && x < m - 1) {
    // ㅗ
    answer = max(answer, board[y][x - 1] + board[y][x] + board[y][x + 1] +
                             board[y - 1][x]);
  }
  if (0 < y && y < n - 1 && x < m - 1) {
    // ㅏ
    answer = max(answer, board[y - 1][x] + board[y][x] + board[y + 1][x] +
                             board[y][x + 1]);
  }
  if (y < n - 1 && 0 < x && x < m - 1) {
    // ㅜ
    answer = max(answer, board[y][x - 1] + board[y][x] + board[y][x + 1] +
                             board[y + 1][x]);
  }
  if (0 < y && y < n - 1 && 0 < x) {
    // ㅓ
    answer = max(answer, board[y - 1][x] + board[y][x] + board[y + 1][x] +
                             board[y][x - 1]);
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      visited[i][j] = true;
      memset(visited, false, sizeof(visited));
      dfs(i, j, board[i][j], 0);
      other(i, j);
      visited[i][j] = false;
    }
  }
  printf("%d\n", answer);
}