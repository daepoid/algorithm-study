#include <bits/stdc++.h>
#define MAX 100
using namespace std;
int N, answer = 2100000000;
int board[MAX][MAX], labeled[MAX][MAX];

struct Coordinate {
  int y;
  int x;
};
Coordinate pos[4];

void calculate() {
  int sum[5] = {0, 0, 0, 0, 0};
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      sum[labeled[i][j] - 1] += board[i][j];
    }
  }
  sort(sum, sum + 5);
  answer = min(answer, sum[4] - sum[0]);
}

void seperate() {
  int weight;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      labeled[i][j] = 5;
    }
  }

  weight = 0;
  for (int i = 0; i < pos[1].y; i++) {
    if (i >= pos[0].y) {
      weight++;
    }
    for (int j = 0; j <= pos[0].x - weight; j++) {
      labeled[i][j] = 1;
    }
  }

  weight = 0;
  for (int i = 0; i <= pos[2].y; i++) {
    if (i > pos[0].y) {
      weight++;
    }
    for (int j = pos[0].x + 1 + weight; j < N; j++) {
      labeled[i][j] = 2;
    }
  }

  weight = 0;
  for (int i = N - 1; i >= pos[1].y; i--) {
    if (i < pos[3].y) {
      weight++;
    }
    for (int j = 0; j < pos[3].x - weight; j++) {
      labeled[i][j] = 3;
    }
  }

  weight = 0;
  for (int i = N - 1; i > pos[2].y; i--) {
    if (i <= pos[3].y) {
      weight++;
    }
    for (int j = pos[3].x + weight; j < N; j++) {
      labeled[i][j] = 4;
    }
  }
  calculate();
}

bool isvalid(int y, int x, int d1, int d2) {
  if (y + d1 >= N || x - d1 < 0) {
    return false;
  }
  if (y + d2 >= N || x + d2 >= N) {
    return false;
  }
  if (y + d1 + d2 >= N || x - d1 + d2 >= N) {
    return false;
  }
  if (y + d2 + d1 >= N || x + d2 - d1 < 0) {
    return false;
  }
  return true;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int d1 = 1; d1 <= j; d1++) {
        for (int d2 = 1; d2 < N - j; d2++) {
          if (isvalid(i, j, d1, d2)) {
            pos[0].y = i;
            pos[0].x = j;
            pos[1].y = i + d1;
            pos[1].x = j - d1;
            pos[2].y = i + d2;
            pos[2].x = j + d2;
            pos[3].y = i + d1 + d2;
            pos[3].x = j - d1 + d2;
            seperate();
          }
        }
      }
    }
  }
  printf("%d\n", answer);
}