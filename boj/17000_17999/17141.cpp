#include <bits/stdc++.h>
#define MAX 51
#define INF 1000000
using namespace std;

int n, m, board[MAX][MAX], visited[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
vector<pair<int, int>> v;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < n && 0 <= newx && newx < n;
}

int max_dist = 0;

void bfs(int y, int x) {
  int dist = 0;
  queue<pair<pair<int, int>, int>> q;
  q.push(make_pair(make_pair(y, x), 0));
  visited[y][x] = 0;

  while (!q.empty()) {
    y = q.front().first.first;
    x = q.front().first.second;
    dist = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (!isvalid(newy, newx)) {
        continue;
      } else if (board[newy][newx] == 1) {
        continue;
      } else if (visited[newy][newx] < dist + 1) {
        continue;
      }
      visited[newy][newx] = dist + 1;
      q.push(make_pair(make_pair(newy, newx), dist + 1));
    }
  }
}

bool check_board() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] != 1 && visited[i][j] == INF) {
        return false;
      } else if (board[i][j] != 1 && visited[i][j] != INF) {
        max_dist = max(max_dist, visited[i][j]);
      }
    }
  }
  return true;
}

void init_visited() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      visited[i][j] = INF;
    }
  }
}

int main() {
  int answer = -1;
  vector<int> arr;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &board[i][j]);
      if (board[i][j] == 2) {
        v.push_back(make_pair(i, j));
      }
    }
  }
  for (int i = 0; i < v.size(); i++) {
    if (i < m) {
      arr.push_back(1);
    } else {
      arr.push_back(0);
    }
  }

  do {
    max_dist = 0;
    init_visited();
    for (int i = 0; i < v.size(); i++) {
      if (arr[i] == 1) {
        bfs(v[i].first, v[i].second);
      }
    }
    if (check_board()) {
      if (answer == -1) {
        answer = max_dist;
      } else {
        answer = min(answer, max_dist);
      }
    }
  } while (prev_permutation(arr.begin(), arr.end()));
  printf("%d\n", answer);
}