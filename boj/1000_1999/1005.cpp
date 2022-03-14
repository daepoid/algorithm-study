#include <bits/stdc++.h>
#define MAX 1111
#define INF 987654321
using namespace std;

int N, K, W;
int build_time[MAX], visited[MAX];
bool board[MAX][MAX];

void game() {
  queue<int> q;
  q.push(1);
  visited[1] = build_time[1];

  while (!q.empty()) {
    int num = q.front();
    q.pop();
    if (num == W) {
      return;
    }

    for (int i = 1; i < N + 1; i++) {
      if (i == num) {
        continue;
      }
      if (!board[num][i]) {
        continue;
      }
      if (visited[i] < visited[num] + build_time[num]) {
        continue;
      }
      visited[i] = visited[num] + build_time[num];
      q.push(i);
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T-- > 0) {
    memset(board, false, sizeof(board));
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
      scanf("%d", &build_time[i + 1]);
      visited[i + 1] = INF;
    }
    for (int i = 0; i < K; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      board[a][b] = true;
    }
    scanf("%d", &W);
    game();
    printf("%lld\n", visited[W]);
  }
}