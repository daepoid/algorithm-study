#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int board[5][5][5], temp[5][5][5], answer = INF;
int visited[5][5][5];
int arr[5] = {0, 1, 2, 3, 4};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dx[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void make_temp_board() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        temp[i][j][k] = board[arr[i]][j][k];
      }
    }
  }
}

bool isvalid(int newy, int newx, int newz) {
  return 0 <= newy && newy < 5 && 0 <= newx && newx < 5 && 0 <= newz &&
         newz < 5;
}

void bfs() {
  queue<pair<pair<int, int>, int>> q;
  q.push(make_pair(make_pair(0, 0), 0));
  visited[0][0][0] = 1;

  while (!q.empty()) {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int z = q.front().second;
    int cnt = visited[z][y][x];

    if (z == 4 && y == 4 && x == 4) {
      answer = min(answer, cnt);
    }

    // 같은 층에서
    for (int i = 0; i < 6; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];
      int newz = z + dz[i];

      if (!isvalid(newy, newx, newz)) {
        continue;
      }
      if (temp[newz][newy][newx] == 0) {
        continue;
      }
      if (visited[newz][newy][newx]) {
        continue;
      }
      visited[newz][newy][newx] = true;
      q.push(make_pair(make_pair(newy, newx), newz));
    }
  }
}

int main() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        scanf("%d", &board[i][j][k]);
      }
    }
  }

  do {
    if (board[arr[4]][4][4] == 1) {
      make_temp_board();
      memset(visited, 0, sizeof(visited));
      bfs();
    }
  } while (next_permutation(arr, arr + 5));
  if (answer == INF) {
    printf("-1\n");
  } else {
    printf("%d\n", answer - 1);
  }
}