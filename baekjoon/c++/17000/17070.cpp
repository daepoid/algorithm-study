#include <bits/stdc++.h>
#define MAX 17
using namespace std;

int N, answer = 0;
int board[MAX][MAX];
int dy[3] = {0, 1, 1};
int dx[3] = {1, 1, 0};

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

bool ispossible(int y, int x, int state) {
  if (state == 0 || state == 2) {
    int newy = y + dy[state];
    int newx = x + dx[state];
    if (board[newy][newx] == 0) {
      return true;
    } else {
      return false;
    }
  } else if (state == 1) {
    for (int i = 0; i < 3; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (board[newy][newx] == 1) {
        return false;
      }
    }
    return true;
  } else {
    printf("ERROR\n");
    return false;
  }
}

void dfs(int y, int x, int state) {
  if (y == N - 1 && x == N - 1) {
    answer++;
    return;
  }
  for (int i = 0; i < 3; i++) {
    int newy = y + dy[i];
    int newx = x + dx[i];
    if (!isvalid(newy, newx)) {
      continue;
    }
    if (state + 2 == i || state - 2 == i) {
      continue;
    }
    if (!ispossible(y, x, i)) {
      continue;
    }
    dfs(newy, newx, i);
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  dfs(0, 1, 0);
  printf("%d\n", answer);
}