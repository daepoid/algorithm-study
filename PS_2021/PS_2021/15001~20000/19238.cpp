#include <bits/stdc++.h>
#define MAX 20
using namespace std;

struct PASSENGER {
  int y;
  int x;
  int desty;
  int destx;
};

struct INFO {
  int y;
  int x;
  int dist;
  int num;
};

int N, M, fuel;
int board[MAX][MAX];
pair<int, int> taxi;
PASSENGER passengers[MAX * MAX + 1];

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

bool cmp(INFO a, INFO b) {
  if (a.dist < b.dist) {
    return true;
  } else if (a.dist == b.dist) {
    if (a.y < b.y) {
      return true;
    } else if (a.y == b.y) {
      if (a.x < b.x) {
        return true;
      }
      return false;
    }
    return false;
  }
  return false;
}

bool bfs(int a, int b, int c, int d) {
  bool visited[MAX][MAX] = {
      false,
  };
  queue<pair<pair<int, int>, pair<int, int>>> q;
  q.push({{a, b}, {0, fuel}});
  visited[a][b] = true;

  while (!q.empty()) {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int dist = q.front().second.first;
    int spare = q.front().second.second;
    q.pop();

    if (y == c && x == d) {
      fuel -= dist;
      fuel += (dist * 2);
      taxi.first = y;
      taxi.second = x;
      return true;
    }
    if (spare < 0) {
      return false;
    }
    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];

      if (isvalid(newy, newx) && board[newy][newx] != -1 &&
          !visited[newy][newx]) {
        visited[newy][newx] = true;
        q.push({{newy, newx}, {dist + 1, spare - 1}});
      }
    }
  }
  return false;
}

int find_shortest_passenger() {
  bool visited[MAX][MAX] = {
      false,
  };
  queue<pair<pair<int, int>, pair<int, int>>> q;
  q.push({{taxi.first, taxi.second}, {0, fuel}});
  visited[taxi.first][taxi.second] = true;
  vector<INFO> v;

  while (!q.empty()) {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int dist = q.front().second.first;
    int spare = q.front().second.second;
    q.pop();

    if (board[y][x] >= 1) {
      v.push_back({y, x, dist, board[y][x]});
    }
    if (spare == 0) {
      continue;
    }

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (isvalid(newy, newx) && board[newy][newx] != -1 &&
          !visited[newy][newx]) {
        visited[newy][newx] = true;
        q.push({{newy, newx}, {dist + 1, spare - 1}});
      }
    }
  }
  if (v.size() == 0) {
    return -1;
  }
  sort(v.begin(), v.end(), cmp);
  board[v[0].y][v[0].x] = 0;
  fuel -= v[0].dist;
  return v[0].num;
}

int main() {
  scanf("%d %d %d", &N, &M, &fuel);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
      if (board[i][j] == 1) {
        board[i][j] = -1;
      }
    }
  }

  scanf("%d %d", &taxi.first, &taxi.second);
  taxi.first--;
  taxi.second--;

  int a, b, c, d;
  for (int i = 1; i <= M; i++) {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    passengers[i] = {a - 1, b - 1, c - 1, d - 1};
    board[a - 1][b - 1] = i;
  }

  for (int i = 0; i < M; i++) {
    int num = find_shortest_passenger();
    if (num == -1) {
      printf("-1\n");
      return 0;
    }

    bool flag = bfs(passengers[num].y, passengers[num].x, passengers[num].desty,
                    passengers[num].destx);
    if (!flag) {
      printf("-1\n");
      return 0;
    }
  }
  printf("%d\n", fuel);
}