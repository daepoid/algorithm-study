#include <bits/stdc++.h>
#define MAX 21
using namespace std;

int w, h;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
char board[MAX][MAX];
bool visited[MAX][MAX];
// vector<int> answer;

typedef struct {
  int y;
  int x;
  int dist;
  bool check = false;
} stain;

typedef struct {
  int y;
  int x;
  int cnt;
} robot;

vector<stain> stains;
robot robo;

bool comp(stain a, stain b) { return a.dist < b.dist; }

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < h && 0 <= newx && newx < w;
}

void bfs(int y, int x) {
  memset(visited, false, sizeof(visited));
  int dist = 0;
  queue<pair<pair<int, int>, int>> q;
  q.push(make_pair(make_pair(y, x), dist));
  visited[y][x] = true;

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
      } else if (visited[newy][newx]) {
        continue;
      } else if (board[newy][newx] == 'x') {
        continue;
      }

      visited[newy][newx] = true;
      q.push(make_pair(make_pair(newy, newx), dist + 1));
      if (board[newy][newx] == '*') {
        stains.push_back({newy, newx, dist + 1, true});
      }
    }
  }
}

int main() {
  int starty, startx;
  while (true) {
    scanf("%d %d", &w, &h);
    if (w == 0 && h == 0) {
      break;
    }

    for (int i = 0; i < h; i++) {
      scanf("%s", board[i]);
      for (int j = 0; j < w; j++) {
        if (board[i][j] == 'o') {
          robo.y = i;
          robo.x = j;
          robo.cnt = -1;
        }
      }
    }
    while (true) {
      stains.clear();
      bfs(robo.y, robo.x);
      if (stains.size() == 0) {
        printf("%d\n", robo.cnt);
        // answer.push_back(robo.cnt);
        break;
      } else {
        sort(stains.begin(), stains.end(), comp);
        board[stains[0].y][stains[0].x] = 'o';
        board[robo.y][robo.x] = '.';
        robo.y = stains[0].y;
        robo.x = stains[0].x;
        if (robo.cnt == -1) {
          robo.cnt = stains[0].dist;
        } else {
          robo.cnt += stains[0].dist;
        }
      }
    }
  }
  //   for (int i = 0; i < answer.size(); i++) {
  //     printf("%d\n", answer[i]);
  //   }
}