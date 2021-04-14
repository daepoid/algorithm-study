#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct balls {
  int cnt;
  int ry, rx, by, bx;
};

char board[11][11];
bool visited[11][11][11][11];
int n, m, gy, gx, answer = 2100000000;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

void bfs(int ry, int rx, int by, int bx, int cnt) {
  queue<balls> q;
  balls b = {cnt, ry, rx, by, bx};
  q.push(b);
  visited[ry][rx][by][bx] = true;
  while (!q.empty()) {
    balls newball = q.front();
    q.pop();
    if (newball.cnt > 10) {
      break;
    }
    if (newball.ry == gy && newball.rx == gx) {
      //   answer = min(answer, newball.cnt);
      answer = newball.cnt;
      break;
    }

    for (int i = 0; i < 4; i++) {
      int nry = newball.ry;
      int nrx = newball.rx;
      int nby = newball.by;
      int nbx = newball.bx;
      while (true) {
        nry += dy[i];
        nrx += dx[i];
        if (board[nry][nrx] == '#') {
          nry -= dy[i];
          nrx -= dx[i];
          break;
        } else if (board[nry][nrx] == 'O') {
          break;
        }
      }
      while (true) {
        nby += dy[i];
        nbx += dx[i];
        if (board[nby][nbx] == '#') {
          nby -= dy[i];
          nbx -= dx[i];
          break;
        } else if (board[nby][nbx] == 'O') {
          break;
        }
      }
      if (nry == nby && nrx == nbx) {
        if (i == 0) {
          if (newball.bx > newball.rx) {
            nrx -= dx[i];
          } else {
            nbx -= dx[i];
          }
        } else if (i == 1) {
          if (newball.by > newball.ry) {
            nby -= dx[i];
          } else {
            nry -= dx[i];
          }
        } else if (i == 2) {
          if (newball.bx > newball.rx) {
            nbx -= dx[i];
          } else {
            nrx -= dx[i];
          }
        } else if (i == 3) {
          if (newball.by > newball.ry) {
            nry -= dx[i];
          } else {
            nby -= dx[i];
          }
        }
      }
      if (nby == gy && nbx == gx) {
        continue;
      }
      if (!visited[nry][nrx][nby][nbx]) {
        balls next = {newball.cnt + 1, nry, nrx, nby, nbx};
        q.push(next);
        visited[nry][nrx][nby][nbx] = true;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int redy, redx, bluey, bluex;

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'R') {
        redy = i;
        redx = j;
      } else if (board[i][j] == 'B') {
        bluey = i;
        bluex = j;
      } else if (board[i][j] == 'O') {
        gy = i;
        gx = j;
      }
    }
  }

  bfs(redy, redx, bluey, bluex, 0);
  if (answer > 10) {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", answer);
}