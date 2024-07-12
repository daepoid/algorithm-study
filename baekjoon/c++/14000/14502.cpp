#include <bits/stdc++.h>
using namespace std;

int board[9][9], temp[9][9];
int answer, n, m;
int safecnt;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
queue<pair<int, int>> initq;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < n && 0 <= newx && newx < m;
}

void bfs(int &cnt) {
  queue<pair<int, int>> q = initq;
  int temp2[9][9];
  memcpy(temp2, temp, sizeof(temp));
  int tempcnt = cnt;

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];

      if (!isvalid(newy, newx)) {
        continue;
      } else if (temp2[newy][newx] != 0) {
        continue;
      }
      temp2[newy][newx] = 2;
      tempcnt--;
      q.push(make_pair(newy, newx));
    }
  }
  answer = max(answer, tempcnt);
}

void buildwall(int &cnt, int mywall) {
  if (mywall == 3) {
    bfs(cnt);
    return;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (temp[i][j] == 0) {
        temp[i][j] = 1;
        cnt--;
        buildwall(cnt, mywall + 1);
        temp[i][j] = 0;
        cnt++;
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  safecnt = n * m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &board[i][j]);
      if (board[i][j] != 0) {
        safecnt--;
      }
      if (board[i][j] == 2) {
        initq.push(make_pair(i, j));
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 0) {
        memcpy(temp, board, sizeof(board));
        temp[i][j] = 1;
        safecnt--;
        buildwall(safecnt, 1);
        temp[i][j] = 0;
        safecnt++;
      }
    }
  }
  printf("%d\n", answer);
}