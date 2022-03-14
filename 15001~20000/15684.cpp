#include <bits/stdc++.h>
using namespace std;

int N, M, H, answer = 4;
int board[11][30];
bool visited[11][30];

bool check() {
  for (int i = 1; i < N + 1; i++) {
    int curr = i;
    for (int j = 1; j < H + 1; j++) {
      if (visited[curr][j]) {
        curr++;
      } else if (visited[curr - 1][j]) {
        curr--;
      }
    }
    if (curr != i) {
      return false;
    }
  }
  return true;
}

void sol(int idx, int cnt) {
  if (cnt >= 4) {
    return;
  }
  if (check()) {
    answer = min(answer, cnt);
    return;
  }
  for (int i = idx; i < H + 1; i++) {
    for (int j = 1; j < N; j++) {
      if (visited[j][i] || visited[j - 1][i] || visited[j + 1][i]) {
        continue;
      }
      visited[j][i] = true;
      sol(i, cnt + 1);
      visited[j][i] = false;
    }
  }
}

int main() {
  int a, b;
  scanf("%d %d %d", &N, &M, &H);
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &a, &b);
    visited[b][a] = true;
  }

  sol(1, 0);
  if (answer == 4) {
    answer = -1;
  }
  printf("%d\n", answer);
  return 0;
}