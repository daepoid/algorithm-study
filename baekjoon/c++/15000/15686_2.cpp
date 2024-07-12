#include <bits/stdc++.h>
#define MAX 50
#define MAX_VAL 2100000000
using namespace std;

int n, m, answer = MAX_VAL;
int board[MAX][MAX];
vector<pair<int, int>> house, chicken, v;
bool visited[14];

int sum_distance() {
  int sum = 0;
  for (int i = 0; i < house.size(); i++) {
    int temp = MAX_VAL;
    for (int j = 0; j < v.size(); j++) {
      temp = min(temp, abs(house[i].first - v[j].first) +
                           abs(house[i].second - v[j].second));
    }
    sum += temp;
  }
  return sum;
}

void sol(int idx, int cnt) {
  if (cnt == m) {
    answer = min(answer, sum_distance());
    return;
  }
  for (int i = idx; i < chicken.size(); i++) {
    if (visited[i]) {
      continue;
    }
    visited[i] = true;
    v.push_back(chicken[i]);
    sol(i, cnt + 1);
    visited[i] = false;
    v.pop_back();
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &board[i][j]);
      if (board[i][j] == 1) {
        house.push_back(make_pair(i, j));
      } else if (board[i][j] == 2) {
        chicken.push_back(make_pair(i, j));
      }
    }
  }
  sol(0, 0);
  printf("%d\n", answer);
}