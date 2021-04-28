#include <bits/stdc++.h>
#define MAX 20
using namespace std;

int N, answer = 0;
int board[MAX][MAX], temp[MAX][MAX], ops[10];

void move_right() {
  for (int i = 0; i < N; i++) {
    for (int j = N - 1; j > 0; j--) {
      if (temp[i][j] == 0) {
        for (int k = j - 1; k >= 0; k--) {
          if (temp[i][k] != 0) {
            temp[i][j] = temp[i][k];
            temp[i][k] = 0;
            break;
          }
        }
      }
    }
  }
}

void right() {
  move_right();
  for (int i = 0; i < N; i++) {
    for (int j = N - 1; j > 0; j--) {
      if (temp[i][j] == temp[i][j - 1]) {
        temp[i][j] *= 2;
        temp[i][j - 1] = 0;
      }
    }
  }
  move_right();
}

void move_up() {
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N; j++) {
      if (temp[i][j] == 0) {
        for (int k = i + 1; k < N; k++) {
          if (temp[k][j] != 0) {
            temp[i][j] = temp[k][j];
            temp[k][j] = 0;
            break;
          }
        }
      }
    }
  }
}

void up() {
  move_up();
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N; j++) {
      if (temp[i][j] == temp[i + 1][j]) {
        temp[i][j] *= 2;
        temp[i + 1][j] = 0;
      }
    }
  }
  move_up();
}

void move_left() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - 1; j++) {
      if (temp[i][j] == 0) {
        for (int k = j + 1; k < N; k++) {
          if (temp[i][k] != 0) {
            temp[i][j] = temp[i][k];
            temp[i][k] = 0;
            break;
          }
        }
      }
    }
  }
}

void left() {
  move_left();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - 1; j++) {
      if (temp[i][j] == temp[i][j + 1]) {
        temp[i][j] *= 2;
        temp[i][j + 1] = 0;
      }
    }
  }
  move_left();
}

void move_down() {
  for (int i = N - 1; i > 0; i--) {
    for (int j = 0; j < N; j++) {
      if (temp[i][j] == 0) {
        for (int k = i - 1; k >= 0; k--) {
          if (temp[i][j] == temp[k][j]) {
            temp[i][j] = temp[k][j];
            temp[k][j] = 0;
            break;
          }
        }
      }
    }
  }
}

void down() {
  move_down();
  for (int i = N - 1; i > 0; i--) {
    for (int j = 0; j < N; j++) {
      if (temp[i][j] == temp[i - 1][j]) {
        temp[i][j] *= 2;
        temp[i - 1][j] = 0;
      }
    }
  }
  move_down();
}

void find_biggest() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      answer = max(answer, temp[i][j]);
    }
  }
}

void move() {
  for (int idx = 0; idx < 5; idx++) {
    if (ops[idx] == 0) {
      right();
    } else if (ops[idx] == 1) {
      up();
    } else if (ops[idx] == 2) {
      left();
    } else if (ops[idx] == 3) {
      down();
    }
  }
  find_biggest();
}

void sol(int cnt) {
  if (cnt == 5) {
    memcpy(temp, board, sizeof(board));
    move();
    return;
  }

  for (int i = 0; i < 4; i++) {
    ops[cnt] = i;
    sol(cnt + 1);
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  sol(0);
  printf("%d\n", answer);
  return 0;
}