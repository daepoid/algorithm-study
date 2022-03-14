#include <bits/stdc++.h>
#define MAX 51
#define INF 2100000000
using namespace std;

int N, M, virus_cnt;
int board[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
bool visited[MAX][MAX];

vector<pair<int, int>> v;
vector<int> arr;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

int bfs() {
  int cnt = virus_cnt;
  int usedturn = 0;
  memset(visited, false, sizeof(visited));
  queue<pair<pair<int, int>, int>> q;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == 1) {
      int y = v[i].first;
      int x = v[i].second;
      q.push(make_pair(make_pair(y, x), 0));
      visited[y][x] = true;
      cnt--;
    }
  }

  while (!q.empty()) {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int now = q.front().second;
    usedturn = max(usedturn, now);
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (isvalid(newy, newx) && !visited[newy][newx] &&
          board[newy][newx] != 1) {
        visited[newy][newx] = true;
        q.push(make_pair(make_pair(newy, newx), now + 1));
        cnt--;
      }
    }
  }

  if (cnt == 0) {
    return usedturn;
  } else {
    return INF;
  }
}

int main() {
  scanf("%d %d", &N, &M);
  virus_cnt = N * N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
      if (board[i][j] == 2) {
        v.push_back(make_pair(i, j));
      }
      if (board[i][j] == 1) {
        virus_cnt--;
      }
    }
  }

  for (int i = 0; i < v.size(); i++) {
    if (i < v.size() - M) {
      arr.push_back(0);
    } else {
      arr.push_back(1);
    }
  }

  int answer = INF;
  do {
    answer = min(answer, bfs());
  } while (next_permutation(arr.begin(), arr.end()));
  if (answer == INF) {
    printf("-1\n");
  } else {
    printf("%d\n", answer);
  }
}