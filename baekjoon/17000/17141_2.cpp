#include <bits/stdc++.h>
#define MAX 51
#define INF 50 * 50 + 1
using namespace std;

int n, m, board[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
vector<pair<int, int>> v;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < n && 0 <= newx && newx < n;
}

int max_dist = 0;
int answer = INF;

bool check_board() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] != 1 && !visited[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void bfs(vector<pair<int, int>> selected) {
  int cnt = 0;
  queue<pair<pair<int, int>, int>> q;
  for (int i = 0; i < selected.size(); i++) {
    q.push(make_pair(make_pair(selected[i].first, selected[i].second), 0));
    visited[selected[i].first][selected[i].second] = true;
  }

  while (!q.empty()) {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int dist = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (!isvalid(newy, newx)) {
        continue;
      } else if (board[newy][newx] == 1) {
        continue;
      } else if (visited[newy][newx]) {
        continue;
      }
      visited[newy][newx] = true;
      cnt = max(cnt, dist + 1);
      q.push(make_pair(make_pair(newy, newx), dist + 1));
    }
  }
  if (check_board()) {
    answer = min(answer, cnt);
  }
}

void init_visited() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      visited[i][j] = INF;
    }
  }
}

int main() {
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
    if (i < v.size() - m) {
      arr.push_back(0);
    } else {
      arr.push_back(1);
    }
  }
  vector<pair<int, int>> selected;
  do {
    selected.clear();
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < v.size(); i++) {
      if (arr[i] == 1) {
        selected.push_back(v[i]);
      }
    }
    bfs(selected);
  } while (next_permutation(arr.begin(), arr.end()));
  if (answer == INF) {
    printf("-1\n");
  } else {
    printf("%d\n", answer);
  }
}