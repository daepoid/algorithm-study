#include <bits/stdc++.h>
#define MAX 21
#define RAINBOW 0
#define WALL -1
#define EMPTY -2
using namespace std;

int N, M, answer = 0;
int board[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
bool visited[MAX][MAX];
bool flag = true;
vector<pair<int, int>> rainbows;
pair<int, int> del_pos;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

pair<int, int> bfs(int y, int x) {
  int type = board[y][x];
  int rainbows_cnt = 0;
  int size = 0;
  bool visited2[MAX][MAX] = {
      false,
  };
  queue<pair<int, int>> q;
  q.push({y, x});
  visited2[y][x] = true;

  while (!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];

      if (isvalid(newy, newx)) {
      }
      if (visited2[newy][newx]) {
        continue;
      }
      if (board[newy][newx] == WALL) {
        continue;
      }
      if (board[newy][newx] > 0 && board[newy][newx] != type) {
        continue;
      }
      if (board[newy][newx] == RAINBOW) {
        rainbows_cnt++;
      }
      visited2[newy][newx] = true;
      q.push({newy, newx});
      size++;
    }
  }
  return {size, rainbows_cnt};
}

void find_largest_block() {
  pair<int, int> max_val;
  pair<int, int> max_pos;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j]) {
        pair<int, int> temp = bfs(i, j);
        if (max_val.first < temp.first) {
          max_val.first = temp.first;
          max_pos = {i, j};
        } else if (max_val.first == temp.first) {
          if (max_val.second)
        }
      }
    }
  }
}

void remake_rainbows() {}

void auto_play() {
  memset(visited, false, sizeof(visited));
  find_largest_block();
  delete_largest_block();
  gravity();
  rotate_board();
  gravity();
  remake_rainbows();
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
      if (board[i][j] == 0) {
        rainbows.push_back({i, j});
      }
    }
  }

  while (flag) {
    auto_play();
  }
  printf("%d\n", answer);
}