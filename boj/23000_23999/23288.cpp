#include <bits/stdc++.h>
#define MAX 21
using namespace std;

int N, M, K;
int board[MAX][MAX];

int dir = 0;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int dice[7] = {0, 1, 2, 3, 4, 5, 6};

bool isvalid(int newy, int newx) {
  return 0 < newy && newy < N + 1 && 0 < newx && newx < M + 1;
}

pair<int, int> role_dice(int y, int x) {

  // 위치 변경
  int newy = y + dy[dir];
  int newx = x + dx[dir];

  if (!isvalid(newy, newx)) {
    dir = (dir + 2) % 4;
    newy = y + dy[dir];
    newx = x + dx[dir];
  }

  // dir 방향으로 굴러간 주사위 모습으로 변경
  if (dir == 0) {
    int a6 = dice[6];

    dice[6] = dice[3];
    dice[3] = dice[1];
    dice[1] = dice[4];
    dice[4] = a6;
  } else if (dir == 1) {
    int a6 = dice[6];

    dice[6] = dice[2];
    dice[2] = dice[1];
    dice[1] = dice[5];
    dice[5] = a6;

  } else if (dir == 2) {
    int a6 = dice[6];

    dice[6] = dice[4];
    dice[4] = dice[1];
    dice[1] = dice[3];
    dice[3] = a6;

  } else if (dir == 3) {
    int a6 = dice[6];

    dice[6] = dice[5];
    dice[5] = dice[1];
    dice[1] = dice[2];
    dice[2] = a6;
  }

  // 위치 반환
  return pair<int, int>(newy, newx);
}

int calc_point(int y, int x) {
  int cnt = 1;
  int num = board[y][x];
  bool visited[MAX][MAX];
  memset(visited, false, sizeof(visited));
  queue<pair<int, int>> q;
  q.push({y, x});
  visited[y][x] = true;

  while (!q.empty()) {
    int yy = q.front().first;
    int xx = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newy = yy + dy[i];
      int newx = xx + dx[i];

      if (!isvalid(newy, newx)) {
        continue;
      }
      if (board[newy][newx] != num) {
        continue;
      }
      if (visited[newy][newx]) {
        continue;
      }

      visited[newy][newx] = true;
      q.push({newy, newx});
      cnt++;
    }
  }
  return cnt;
}

void change_dir(int y, int x) {
  if (dice[6] > board[y][x]) {
    dir = (dir + 3) % 4;
  } else if (dice[6] < board[y][x]) {
    dir = (dir + 1) % 4;
  }
}

int main() {
  scanf("%d %d %d", &N, &M, &K);
  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < M + 1; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  int y = 1;
  int x = 1;
  int ans = 0;

  for (int i = 0; i < K; i++) {
    pair<int, int> pos;
    pos = role_dice(y, x);
    y = pos.first;
    x = pos.second;

    ans += calc_point(y, x) * board[y][x];
    change_dir(y, x);
  }
  printf("%d\n", ans);
}