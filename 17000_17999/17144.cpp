#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int r, c, t;
int board[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < r && 0 <= newx && newx < c;
}

void print_board() {
  printf("\n\n----------------------------------------\n");
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (j == c - 1) {
        printf("%d\n", board[i][j]);
      } else {
        printf("%d ", board[i][j]);
      }
    }
  }
  printf("\n\n----------------------------------------\n");
}

int sol(int ar) {
  int temp_board[MAX][MAX];
  while (t-- > 0) {
    memset(temp_board, 0, sizeof(temp_board));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (board[i][j] == 0) {
          continue;
        }
        int cnt = 0;
        for (int k = 0; k < 4; k++) {
          int newy = i + dy[k];
          int newx = j + dx[k];
          if (!isvalid(newy, newx)) {
            continue;
          } else if ((newy == ar || newy == ar + 1) && newx == 0) {
            continue;
          }
          cnt++;
          temp_board[newy][newx] += board[i][j] / 5;
        }
        temp_board[i][j] -= (board[i][j] / 5) * cnt;
      }
    }
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        board[i][j] += temp_board[i][j];
      }
    }

    for (int i = ar - 1; i > 0; i--) {
      board[i][0] = board[i - 1][0];
    }
    for (int i = 0; i < c - 1; i++) {
      board[0][i] = board[0][i + 1];
    }
    for (int i = 0; i < ar; i++) {
      board[i][c - 1] = board[i + 1][c - 1];
    }
    for (int i = c - 1; i > 1; i--) {
      board[ar][i] = board[ar][i - 1];
    }
    board[ar][1] = 0;

    for (int i = ar + 2; i < r - 1; i++) {
      board[i][0] = board[i + 1][0];
    }
    for (int i = 0; i < c - 1; i++) {
      board[r - 1][i] = board[r - 1][i + 1];
    }
    for (int i = r - 1; i > ar + 1; i--) {
      board[i][c - 1] = board[i - 1][c - 1];
    }
    for (int i = c - 1; i > 1; i--) {
      board[ar + 1][i] = board[ar + 1][i - 1];
    }
    board[ar + 1][1] = 0;
  }

  int count = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      count += board[i][j];
    }
  }
  return count + 2;
}

int main() {
  int ar, ac;
  scanf("%d %d %d", &r, &c, &t);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      scanf("%d", &board[i][j]);
      if (board[i][j] == -1) {
        ar = i - 1;
      }
    }
  }
  printf("%d\n", sol(ar));
}