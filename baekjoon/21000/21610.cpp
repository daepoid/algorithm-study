#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int N, M;
int board[MAX][MAX];
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
bool cloud[MAX][MAX];
bool deleted_cloud[MAX][MAX];
bool newcloud[MAX][MAX];

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

void move_cloud(int d, int s) {
  int my = dy[d] * s;
  int mx = dx[d] * s;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int newy = i + my;
      int newx = j + mx;
      while (newy < 0) {
        newy += N;
      }
      while (newy >= N) {
        newy -= N;
      }
      while (newx < 0) {
        newx += N;
      }
      while (newx >= N) {
        newx -= N;
      }
      newcloud[newy][newx] = cloud[i][j];
    }
  }
  memcpy(cloud, newcloud, sizeof(newcloud));
}

void start_rain() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (cloud[i][j]) {
        board[i][j]++;
      }
    }
  }
}

void delete_cloud() {
  memcpy(deleted_cloud, cloud, sizeof(cloud));
  memset(cloud, false, sizeof(cloud));
}

void water_copy_bug() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int cnt = 0;
      if (!deleted_cloud[i][j]) {
        continue;
      }
      for (int a = 1; a < 8; a += 2) {
        int newy = i + dy[a];
        int newx = j + dx[a];

        if (!isvalid(newy, newx)) {
          continue;
        }
        if (board[newy][newx] == 0) {
          continue;
        }
        cnt++;
      }
      board[i][j] += cnt;
    }
  }
}

void build_cloud() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] >= 2 && !deleted_cloud[i][j]) {
        cloud[i][j] = true;
        board[i][j] -= 2;
      }
    }
  }
}

int main() {
  int d, s;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  cloud[N - 1][0] = true;
  cloud[N - 1][1] = true;
  cloud[N - 2][0] = true;
  cloud[N - 2][1] = true;
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &d, &s);
    move_cloud(d - 1, s);
    start_rain();
    delete_cloud();
    water_copy_bug();
    build_cloud();
    memset(deleted_cloud, false, sizeof(deleted_cloud));
  }
  int answer = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      answer += board[i][j];
    }
  }
  printf("%d\n", answer);
}