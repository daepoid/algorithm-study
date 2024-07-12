#include <bits/stdc++.h>
#define MAX 21
using namespace std;

int N, answer = 0;
int board[MAX][MAX];
int db[MAX * MAX + 1][4];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

int count_near_friends(int y, int x, int num) {
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    int newy = y + dy[i];
    int newx = x + dx[i];
    if (!isvalid(newy, newx)) {
      continue;
    }
    for (int j = 0; j < 4; j++) {
      if (board[newy][newx] == db[num][j]) {
        cnt++;
        break;
      }
    }
  }
  return cnt;
}

int zero_count(int y, int x) {
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    int newy = y + dy[i];
    int newx = x + dx[i];
    if (!isvalid(newy, newx)) {
      continue;
    }
    if (board[newy][newx] == 0) {
      cnt++;
    }
  }
  return cnt;
}

void set_seat(int num) {
  int max_cnt = 0;
  pair<int, int> max_pos = {-1, -1};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] != 0) {
        continue;
      }
      int near_friends_cnt = count_near_friends(i, j, num);
      if (max_cnt < near_friends_cnt) {
        max_cnt = near_friends_cnt;
        max_pos = {i, j};
      } else if (max_cnt == near_friends_cnt) {
        int z_cnt = zero_count(max_pos.first, max_pos.second);
        int newz_cnt = zero_count(i, j);
        if (z_cnt < newz_cnt) {
          max_pos = {i, j};
        } else if (z_cnt == newz_cnt) { // 3번 조건
          if (max_pos.first > i) {
            max_pos = {i, j};
          } else if (max_pos.first == i) { // 3번 조건, 행이 같은 경우
            if (max_pos.second > j) {
              max_pos = {i, j};
            }
          }
        }
      }
    }
  }
  board[max_pos.first][max_pos.second] = num;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N * N; i++) {
    int idx, temp;
    scanf("%d", &idx);
    for (int j = 0; j < 4; j++) {
      scanf("%d", &db[idx][j]);
    }
    set_seat(idx);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int temp = count_near_friends(i, j, board[i][j]);
      temp = pow(10, temp - 1);
      answer += temp;
    }
  }
  printf("%d\n", answer);
}