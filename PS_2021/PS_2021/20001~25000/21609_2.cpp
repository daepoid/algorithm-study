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

int bfs(int i, int j) {
  int num = board[i][j];
  int cnt = 1;
  queue<pair<int, int>> q;
  visited[i][j] = true;
  q.push({i, j});

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < N; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (!isvalid(newy, newx)) {
        continue;
      }
      if (visited[newy][newx]) {
        continue;
      }
      if (board[newy][newx] == WALL) {
        continue;
      }
      if (board[newy][newx] == RAINBOW || board[newy][newx] == num) {
        visited[newy][newx] = true;
        q.push({newy, newx});
        cnt++;
      }
    }
  }
  return cnt;
}

void find_largest_block() {
  int now_cnt, max_cnt;
  pair<int, int> max_pos; // <y, x>
  max_cnt = -1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (visited[i][j]) {
        continue;
      }
      if (board[i][j] == WALL) {
        continue;
      }
      if (board[i][j] == EMPTY) {
        continue;
      }
      if (board[i][j] == RAINBOW) {
        continue;
      }
      now_cnt = bfs(i, j);
      for (int k = 0; k < rainbows.size(); k++) {
        int y = rainbows[k].first;
        int x = rainbows[k].second;
        visited[y][x] = false;
      }
      if (max_cnt < now_cnt) {
        max_cnt = now_cnt;
        max_pos = {i, j};
      } else if (max_cnt == now_cnt) {
        if (max_pos.first > i) {
          max_pos = {i, j};
        } else if (max_pos.first == i) {
          if (max_pos.second > j) {
            max_pos = {i, j};
          }
        }
      }
    }
  }
  del_pos = {max_pos.first, max_pos.second};
  if (max_cnt < 2) {
    flag = false;
  } else if (max_cnt >= 2) {
    answer += (max_cnt * max_cnt);
  }
}

void delete_largest_block() {
  int y = del_pos.first;
  int x = del_pos.second;
  int num = board[y][x];
  bool visited2[MAX][MAX] = {
      false,
  };
  queue<pair<int, int>> q;
  q.push({y, x});
  visited2[y][x] = true;
  board[y][x] = EMPTY;

  while (!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];

      if (!isvalid(newy, newx)) {
        continue;
      }
      if (visited2[newy][newx]) {
        continue;
      }
      if (board[newy][newx] == num || board[newy][newx] == RAINBOW) {
        q.push({newy, newx});
        visited2[newy][newx] = true;
        board[newy][newx] = EMPTY;
      }
    }
  }
  del_pos = {N + 1, N + 1};
}

void gravity() {
  for (int j = 0; j < N; j++) {
    for (int i = N - 1; i > 0; i--) {
      if (board[i][j] == EMPTY) {
        for (int k = i - 1; k >= 0; k--) {
          if (board[k][j] >= 0) {
            swap(board[i][j], board[k][j]);
            break;
          }
        }
      }
    }
  }
}

void rotate_board() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      swap(board[i][j], board[j][i]);
    }
  }
  for (int i = 0; i < N / 2; i++) {
    for (int j = 0; j < N; j++) {
      swap(board[i][j], board[N - 1 - i][j]);
    }
  }
}

void remake_rainbows() {
  rainbows.clear();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 0) {
        rainbows.push_back({i, j});
      }
    }
  }
}

void auto_play() {
  memset(visited, false, sizeof(visited));
  // 최대 위치를 찾고, del_pos에 저장
  find_largest_block();
  if (flag) {
    delete_largest_block();
    gravity();
    rotate_board();
    gravity();
    remake_rainbows();
  }
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