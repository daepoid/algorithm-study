#include <bits/stdc++.h>
#define MAX 100
using namespace std;

vector<pair<int, char>> orders;
int N, K, L, X, answer = 0;
char C[3];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
bool visited[MAX][MAX], apples[MAX][MAX];

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

void sol(int newy, int newx, int d) {
  int idx = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(newy, newx));
  visited[newy][newx] = true;

  while (true) {
    answer++;
    // 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
    newy += dy[d];
    newx += dx[d];
    if (!isvalid(newy, newx)) {
      return;
    }
    if (visited[newy][newx]) {
      return;
    }

    visited[newy][newx] = true;
    q.push(make_pair(newy, newx));
    if (apples[newy][newx]) {
      // 만약 이동한 칸에 사과가 있다면,
      // 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
      apples[newy][newx] = false;
    } else {
      // 만약 이동한 칸에 사과가 없다면,
      // 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다.
      // 즉, 몸길이는 변하지 않는다.
      visited[q.front().first][q.front().second] = false;
      q.pop();
    }

    if (orders[idx].first == answer) {
      if (orders[idx].second == 'D') {
        d = (d + 3) % 4;
      } else if (orders[idx].second == 'L') {
        d = (d + 1) % 4;
      }
      idx++;
    }
  }
}

int main() {
  scanf("%d", &N);
  scanf("%d", &K);
  for (int i = 0; i < K; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    apples[a - 1][b - 1] = true;
  }
  scanf("%d", &L);
  for (int i = 0; i < L; i++) {
    scanf("%d %s", &X, C);
    orders.push_back(make_pair(X, C[0]));
  }
  sol(0, 0, 0);
  printf("%d\n", answer);
}