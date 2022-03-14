#include <bits/stdc++.h>
#define MAX 64
using namespace std;

int N, Q, board_len;
int board[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
bool visited[MAX][MAX];

void print_board() {
  printf("\n\n");
  for (int i = 0; i < board_len; i++) {
    for (int j = 0; j < board_len; j++) {
      if (j == board_len - 1) {
        printf("%d\n", board[i][j]);
      } else {
        printf("%d ", board[i][j]);
      }
    }
  }
  printf("\n");
}

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < board_len && 0 <= newx && newx < board_len;
}

void rotate_mini(int y, int x, int size) {
  int temp[MAX][MAX];
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      temp[y + j][x + size - i - 1] = board[y + i][x + j];
    }
  }
  for (int i = y; i < y + size; i++) {
    for (int j = x; j < x + size; j++) {
      board[i][j] = temp[i][j];
    }
  }
}

void firestorm(int num) {
  int L_size = pow(2, num);
  int newboard[MAX][MAX];
  for (int i = 0; i < board_len; i += L_size) {
    for (int j = 0; j < board_len; j += L_size) {
      rotate_mini(i, j, L_size);
    }
  }

  for (int i = 0; i < board_len; i++) {
    for (int j = 0; j < board_len; j++) {
      if (board[i][j] == 0) {
        newboard[i][j] = 0;
        continue;
      }
      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        int newy = i + dy[k];
        int newx = j + dx[k];
        if (!isvalid(newy, newx)) {
          continue;
        }
        if (board[newy][newx] == 0) {
          continue;
        }
        cnt++;
      }
      if (cnt < 3) {
        newboard[i][j] = board[i][j] - 1;
      } else {
        newboard[i][j] = board[i][j];
      }
    }
  }
  memcpy(board, newboard, sizeof(newboard));
}

int bfs(int a, int b) {
  int cnt = 1;
  queue<pair<int, int>> q;
  q.push({a, b});
  visited[a][b] = true;

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];

      if (!isvalid(newy, newx)) {
        continue;
      }
      if (board[newy][newx] == 0) {
        continue;
      }
      if (visited[newy][newx]) {
        continue;
      }
      visited[newy][newx] = true;
      q.push({newy, newx});
      cnt++;
    }
  }
  return cnt;
}

int main() {
  scanf("%d %d", &N, &Q);
  board_len = pow(2, N);
  for (int i = 0; i < board_len; i++) {
    for (int j = 0; j < board_len; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  int temp;
  for (int i = 0; i < Q; i++) {
    scanf("%d", &temp);
    firestorm(temp);
  }
  int sum_ice = 0;
  int max_ice = 0;
  for (int i = 0; i < board_len; i++) {
    for (int j = 0; j < board_len; j++) {
      sum_ice += board[i][j];
    }
  }
  for (int i = 0; i < board_len; i++) {
    for (int j = 0; j < board_len; j++) {
      if (visited[i][j]) {
        continue;
      }
      if (board[i][j] == 0) {
        continue;
      }
      max_ice = max(max_ice, bfs(i, j));
    }
  }
  printf("%d\n%d\n", sum_ice, max_ice);
}