#include <bits/stdc++.h>
#define MAX 20
using namespace std;

int N, M, fuel, answer = 0;
int board[MAX][MAX];
pair<int, int> taxi;
vector<pair<pair<int, int>, pair<int, int>>> v;

void bfS() {}

int main() {
  scanf("%d %d %d", &N, &M, &fuel);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  scanf("%d %d", &taxi.first, &taxi.second);
  int a, b, c, d;
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    v.push_back({{a, b}, {c, d}});
  }
  for (int i = 0; i < M; i++) {
    bfs();
  }
  printf("%d\n", answer);
}