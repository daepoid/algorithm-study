#include <bits/stdc++.h>
#define MAX 101
using namespace std;

vector<int> dirs;
int board[MAX][MAX];
int n;
int x, y, d, g;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

void dragon_curve() {
  for (int i = dirs.size() - 1; i >= 0; i--) {
    int newdir = (dirs[i] + 1) % 4;
    y = y + dy[newdir];
    x = x + dx[newdir];
    board[y][x] = 1;
    dirs.push_back(newdir);
  }
}

int main() {
  int answer = 0;
  scanf("%d", &n);
  while (n-- > 0) {
    scanf("%d %d %d %d", &x, &y, &d, &g);
    dirs.clear();

    board[y][x] = 1;
    y = y + dy[d];
    x = x + dx[d];
    board[y][x] = 1;

    dirs.push_back(d);
    for (int i = 0; i < g; i++) {
      dragon_curve();
    }
  }
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j] == 1 &&
          board[i + 1][j + 1] == 1) {
        answer++;
      }
    }
  }
  printf("%d\n", answer);
}