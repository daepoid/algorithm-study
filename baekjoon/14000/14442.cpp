#include <bits/stdc++.h>
using namespace std;

int n, m, num;
int origin[1001][1001];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int visited[1001][1001];
map<int, int> db;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < n && 0 <= newx && newx < m;
}

void bfs(int y, int x, int checknum) {
  int cnt = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(y, x));
  visited[y][x] = checknum;

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (!isvalid(newy, newx) ||
          origin[newy][newx] != 0 && visited[newy][newx] > 0) {
        continue;
      }
      visited[newy][newx] = checknum;
      cnt++;
      q.push(make_pair(newy, newx));
    }
  }
  db[checknum] = cnt;
}

void checkone(int y, int x) {
  int sum = 0;
  set<int> temp;
  for (int i = 0; i < 4; i++) {
    int newy = y + dy[i];
    int newx = x + dx[i];
    if (!isvalid(newy, newx)) {
      continue;
    }
    if (temp.find(visited[newy][newx]) == temp.end()) {
      temp.insert(visited[newy][newx]);
      sum = sum + db[visited[newy][newx]];
    }
  }
  visited[y][x] = sum;
}

int main() {
  char temp[1001];
  int checknum = 1;
  vector<pair<int, int>> v;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", temp);
    for (int j = 0; j < m; j++) {
      origin[i][j] = temp[j] - '0';
      if (origin[i][j] == 1) {
        v.push_back(make_pair(i, j));
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (origin[i][j] == 0 && visited[i][j] == 0) {
        bfs(v[i].first, v[i].second, checknum++);
      }
    }
  }

  for (int i = 0; i < v.size(); i++) {
    checkone(v[i].first, v[i].second);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (origin[i][j] == 0) {
        printf("0");
      } else {
        printf("%d", visited[i][j] % 10);
      }
    }
    printf("\n");
  }
}