#include <bits/stdc++.h>
#define MAX 1111
#define INF 987654321
using namespace std;

int N, K, W, answer = 0;
int build_time[MAX], start_time[MAX], end_time[MAX];
vector<int> conn[MAX];

void init() {}

void input() {
  scanf("%d %d", &N, &K);
  for (int i = 1; i < N + 1; i++) {
    scanf("%d", &build_time[i]);
  }
  for (int i = 0; i < K; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    conn[a].push_back(b);
  }
  scanf("%d", &W);
}

void game() {
  queue<int> q;
  q.push();
}

int main() {
  int T;
  scanf("%d", &T);
  while (T-- > 0) {
    init();
    input();
    game();
  }
}