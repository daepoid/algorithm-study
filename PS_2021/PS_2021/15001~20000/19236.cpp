#include <bits/stdc++.h>
#define MAX 4
using namespace std;

struct FISH {
  int y;
  int x;
  int dir;
  bool live;
};

int board[MAX][MAX], answer = 0;
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
FISH shark, fishes[MAX * MAX + 1];
bool flag = true;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < MAX && 0 <= newx && newx < MAX;
}

bool isshark(int newy, int newx) {
  if (shark.y == newy && shark.x == newx) {
    return true;
  } else {
    return false;
  }
}

void move_fish() {
  for (int i = 0; i < MAX * MAX; i++) {
    int y = fishes[i].y;
    int x = fishes[i].x;
    int dir = fishes[i].dir;

    for (int j = 0; j < 8; j++) {
      int newy = y + dy[(dir + j) % 8];
      int newx = x + dx[(dir + j) % 8];
      if (!isvalid(newy, newx)) {
        continue;
      }
      if (isshark(newy, newx)) {
        continue;
      }

      swap(board[y][x], board[newy][newx]);
      fishes[i].y = newy;
      fishes[i].x = newx;
      if (board[y][x] != -1) {
        fishes[board[y][x]].y = y;
        fishes[board[y][x]].x = x;
      }
      break;
    }
  }
}

void move_shark() {
  int y = shark.y + dy[shark.dir];
  int x = shark.x + dx[shark.dir];
  int dir = fishes[board[y][x]].dir;

  if (board[y][x] != -1) {
    answer += board[y][x];
    fishes[board[y][x]].y = -1;
    fishes[board[y][x]].x = -1;
    fishes[board[y][x]].dir = -1;
    board[y][x] = -1;
  }
}

void dfs(int y, int x, int dir, int sum) {
  answer = max(answer, sum);
  int temp[4][4];
  FISH temp_fishes[MAX * MAX + 1];
  copy_state(temp, board, temp_fishes, fishes);

  move_fish();

  for (int i = 1; i <= 3; i++) {
    int newy = y + dy[dir] * i;
  }
}

int main() {
  int a, b;
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      scanf("%d %d", &a, &b);
      board[i][j] = a;
      fishes[a] = {i, j, b, true};
    }
  }

  int temp = board[0][0];
  int dir = fishes[temp].dir;
  fishes[temp].live = false;

  shark.y = 0;
  shark.x = 0;
  shark.dir = fishes[temp].dir;
  board[0][0] = -1;

  dfs(0, 0, dir, temp);
  printf("%d\n", answer);
}