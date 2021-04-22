#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int N, M;
char board[MAX][MAX], temp[MAX][MAX], answer[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < M;
}

int bfs(int y, int x) {
  int cnt = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(y, x));
  memcpy(temp, board, sizeof(board));
  temp[y][x] = '2';

  while (!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();
    cnt++;

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];

      if (isvalid(newy, newx) && temp[newy][newx] == '0') {
        temp[newy][newx] = '2';
        q.push(make_pair(newy, newx));
      }
    }
  }
  return cnt;
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%s", &board[i]);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == '0') {
        answer[i][j] = board[i][j];
      } else {
        answer[i][j] = '0' + (bfs(i, j) % 10);
      }
    }
    answer[i][M] = '\0';
  }
  for (int i = 0; i < N; i++) {
    printf("%s\n", answer[i]);
  }
}