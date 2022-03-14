#include <bits/stdc++.h>
using namespace std;

int n, answer = -1;
int dy[6] = {-2, -2, 0, 0, 2, 2};
int dx[6] = {-1, 1, -2, 2, -1, 1};
bool visited[200][200];
struct pos {
  int y;
  int x;
  int cnt;
};

bool isvalid(pos nowpos) {
  return 0 <= nowpos.y && nowpos.y < n && 0 <= nowpos.x && nowpos.x < n;
}

void bfs(int y, int x, int desty, int destx) {
  queue<pos> q;
  q.push({y, x, 0});
  visited[y][x] = true;

  while (!q.empty()) {
    pos nowpos = q.front();
    q.pop();

    if (nowpos.y == desty && nowpos.x == destx) {
      answer = nowpos.cnt;
      return;
    }

    for (int i = 0; i < 6; i++) {
      pos newpos = {nowpos.y + dy[i], nowpos.x + dx[i], nowpos.cnt + 1};

      if (!isvalid(newpos) || visited[newpos.y][newpos.x]) {
        continue;
      }
      visited[newpos.y][newpos.x] = true;
      q.push(newpos);
    }
  }
}

int main() {
  int a, b, c, d;
  scanf("%d", &n);
  scanf("%d %d %d %d", &a, &b, &c, &d);
  bfs(a, b, c, d);
  printf("%d\n", answer);
}