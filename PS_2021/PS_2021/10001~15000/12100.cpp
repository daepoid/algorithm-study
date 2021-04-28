#include <bits/stdc++.h>
#define MAX 22
using namespace std;

int N, answer;
int board[MAX][MAX], copied_board[MAX][MAX];
int selected[10];

void move_left() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - 1; j++) {
      bool flag = false;
      if (copied_board[i][j] == 0) {
        int k = j + 1;
        while (k <= N - 1) {
          if (copied_board[i][k] != 0) {
            flag = true;
            break;
          }
          k++;
        }
        if (flag) {
          copied_board[i][j] = copied_board[i][k];
          copied_board[i][k] = 0;
        }
      }
    }
  }
}

void left() {
  move_left();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - 1; j++) {
      if (copied_board[i][j] == copied_board[i][j + 1]) {
        copied_board[i][j] = copied_board[i][j] * 2;
        copied_board[i][j + 1] = 0;
      }
    }
  }
  move_left();
}

void move_right() {
  for (int i = 0; i < N; i++) {
    for (int j = N - 1; j > 0; j--) {
      bool flag = false;
      if (copied_board[i][j] == 0) {
        int k = j - 1;
        while (k >= 0) {
          if (copied_board[i][k] != 0) {
            flag = true;
            break;
          }
          k--;
        }
        if (flag) {
          copied_board[i][j] = copied_board[i][k];
          copied_board[i][k] = 0;
        }
      }
    }
  }
}

void right() {
  move_right();
  for (int i = 0; i < N; i++) {
    for (int j = N - 1; j > 0; j--) {
      if (copied_board[i][j] == copied_board[i][j - 1]) {
        copied_board[i][j] = copied_board[i][j] * 2;
        copied_board[i][j - 1] = 0;
      }
    }
  }
  move_right();
}

void move_up() {
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N; j++) {
      bool flag = false;
      if (copied_board[i][j] == 0) {
        int k = i + 1;
        while (k <= N - 1) {
          if (copied_board[k][j] != 0) {
            flag = true;
            break;
          }
          k++;
        }
        if (flag) {
          copied_board[i][j] = copied_board[k][j];
          copied_board[k][j] = 0;
        }
      }
    }
  }
}

void up() {
  move_up();
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N; j++) {
      if (copied_board[i][j] == copied_board[i + 1][j]) {
        copied_board[i][j] = copied_board[i][j] * 2;
        copied_board[i + 1][j] = 0;
      }
    }
  }
  move_up();
}

void move_down() {
  for (int i = N - 1; i > 0; i--) {
    for (int j = 0; j < N; j++) {
      bool flag = false;
      if (copied_board[i][j] == 0) {
        int k = i - 1;
        while (k >= 0) {
          if (copied_board[k][j] != 0) {
            flag = true;
            break;
          }
          k--;
        }
        if (flag) {
          copied_board[i][j] = copied_board[k][j];
          copied_board[k][j] = 0;
        }
      }
    }
  }
}

void down() {
  move_down();
  for (int i = N - 1; i > 0; i--) {
    for (int j = 0; j < N; j++) {
      if (copied_board[i - 1][j] == copied_board[i][j]) {
        copied_board[i][j] = copied_board[i][j] * 2;
        copied_board[i - 1][j] = 0;
      }
    }
  }
  move_down();
}

void find_large_num() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      answer = max(answer, copied_board[i][j]);
    }
  }
}

void run_game() {
  for (int i = 0; i < 5; i++) {
    if (selected[i] == 0) {
      right();
    } else if (selected[i] == 1) {
      left();
    } else if (selected[i] == 2) {
      up();
    } else if (selected[i] == 3) {
      down();
    }
  }
  find_large_num();
}

void select_dir(int cnt) {
  if (cnt == 5) {
    memcpy(copied_board, board, sizeof(board));
    run_game();
    return;
  }
  for (int i = 0; i < 4; i++) {
    selected[cnt] = i;
    select_dir(cnt + 1);
  }
}

int main() {
  scanf("%d\n", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  select_dir(0);
  printf("%d\n", answer);

  return 0;
}