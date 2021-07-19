#include <bits/stdc++.h>
#define MAX 10
#define INF 987654321
using namespace std;

int N;
int board[MAX][MAX];
int dp_max[MAX][MAX];
int dp_min[MAX][MAX];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 1; j <= 3; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      dp_min[i][j] = INF;
    }
  }

  dp_max[0][1] = board[0][1];
  dp_max[0][2] = board[0][2];
  dp_max[0][3] = board[0][3];

  dp_min[0][1] = board[0][1];
  dp_min[0][2] = board[0][2];
  dp_min[0][3] = board[0][3];

  for (int i = 0; i < N; i++) {
    for (int j = 1; j <= 3; j++) {
      int temp = 0;
      temp = max(temp, dp_max[i % 3][j - 1] + board[i + 1][j]);
      temp = max(temp, dp_max[i % 3][j] + board[i + 1][j]);
      temp = max(temp, dp_max[i % 3][j + 1] + board[i + 1][j]);
      dp_max[(i + 1) % 3][j] = temp;
    }

    for (int j = 1; j <= 3; j++) {
      int temp = INF;
      temp = min(temp, dp_min[i % 3][j - 1] + board[i + 1][j]);
      temp = min(temp, dp_min[i % 3][j] + board[i + 1][j]);
      temp = min(temp, dp_min[i % 3][j + 1] + board[i + 1][j]);
      dp_min[(i + 1) % 3][j] = temp;
    }
  }
  printf("%d %d\n", dp_max[N % 3][2], dp_min[N % 3][2]);
}