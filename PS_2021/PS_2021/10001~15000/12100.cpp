#include <bits/stdc++.h>
#define MAX 22
using namespace std;

int N, answer = 0;
int board[MAX][MAX], copied_board[MAX][MAX], selected[10];

void move_right() {
  for (int i = 0; i < N; i++) {
    for (int j = N - 1; j > 0; j--) {
      bool check = false;
      if (copied_board[i][j] == 0) {
        int k = j - 1;
        while (k >= 0) {
          if (copied_board[i][k] != 0) {
            check = true;
            break;
          }
          k--;
        }
        if (check) {
          copied_board[i][j] = copied_board[i][k];
          copied_board[i][k] = 0;
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = N - 1; j > 0; j--) {
      if (copied_board[i][j] == copied_board[i][j - 1]) {
        copied_board[i][j] *= 2;
        copied_board[i][j - 1] = 0;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = N - 1; j > 0; j--) {
      bool check = false;
      if (copied_board[i][j] == 0) {
        int k = j - 1;
        while (k >= 0) {
          if (copied_board[i][k] != 0) {
            check = true;
            break;
          }
          k--;
        }
        if (check) {
          copied_board[i][j] = copied_board[i][k];
          copied_board[i][k] = 0;
        }
      }
    }
  }
}

void move_left() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - 1; j++){
      
    }
  }
}

void move_down() {}

void move_up() {}

void copy_board() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      copied_board[i][j] = board[i][j];
    }
  }
}

int find_max_val() {
  int max_val = -1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      max_val = max(max_val, copied_board[i][j]);
    }
  }
  return max_val;
}

void play_game() {
  for (int i = 0; i < 5; i++) {
    if (selected[i] == 0) {
      move_right();
    } else if (selected[i] == 1) {
      move_left();
    } else if (selected[i] == 2) {
      move_down();
    } else if (selected[i] == 3) {
      move_up();
    }
  }
  answer = max(answer, find_max_val());
}

void select_direction(int cnt) {
  if (cnt == 5) {
    copy_board();
    play_game();
    return;
  }
  for (int i = 0; i < 4; i++) {
    selected[cnt] = i;
    select_direction(cnt + 1);
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  select_direction(0);
  printf("%d\n", answer);
}