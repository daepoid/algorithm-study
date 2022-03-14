#include <bits/stdc++.h>
#define MAX 9
using namespace std;

int N, M, safety, answer = 0;
int board[MAX][MAX], temp[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
queue<pair<int, int>> initq;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < M;
}

void bfs() {
  queue<pair<int, int>> q = initq;
  int cnt = safety - 3;
  int temp2[MAX][MAX];
  memcpy(temp2, temp, sizeof(temp));

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];

      if (!isvalid(newy, newx)) {
        continue;
      }
      if (temp2[newy][newx] != 0) {
        continue;
      }
      temp2[newy][newx] = 2;
      cnt--;
      q.push(make_pair(newy, newx));
    }
  }
  answer = max(answer, cnt);
}

void make_wall(int cnt) {
  if (cnt == 3) {
    bfs();
    return;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (temp[i][j] == 0) {
        temp[i][j] = 1;
        make_wall(cnt + 1);
        temp[i][j] = 0;
      }
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  safety = N * M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &board[i][j]);
      if (board[i][j] != 0) {
        safety--;
      }
      if (board[i][j] == 2) {
        initq.push(make_pair(i, j));
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 0) {
        memcpy(temp, board, sizeof(board));
        temp[i][j] = 1;
        make_wall(1);
      }
    }
  }
  printf("%d\n", answer);
}