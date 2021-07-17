#include <bits/stdc++.h>
#define MAX 1111
#define INF 987654321
using namespace std;

int N, K, W, answer = 0;
int build_time[MAX], start_time[MAX], end_time[MAX];
bool board[MAX][MAX];

void game() {
  queue<int> q;
  q.push(W);
  start_time[W] = 0;
  end_time[W] = build_time[W];

  while (!q.empty()) {
    int num = q.front();
    q.pop();

    for (int i = 1; i < N + 1; i++) {
      if (i == num) {
        continue;
      }
      if (!board[i][num]) {
        continue;
      }
      if (start_time[i] >= end_time[num]) {
        continue;
      }
      start_time[i] = end_time[num];
      end_time[i] = start_time[i] + build_time[i];
      answer = max(answer, end_time[i]);
      q.push(i);
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T-- > 0) {
    memset(board, false, sizeof(board));
    memset(start_time, -1, sizeof(start_time));
    memset(end_time, 0, sizeof(end_time));
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
      scanf("%d", &build_time[i + 1]);
    }
    for (int i = 0; i < K; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      board[a][b] = true;
    }
    scanf("%d", &W);
    answer = build_time[W];
    game();
    printf("%d\n", answer);
  }
}