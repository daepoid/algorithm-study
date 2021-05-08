#include <bits/stdc++.h>
#define MAX 501
using namespace std;

struct go {
  int x;
  int y;
};

int n, m;
char board[MAX][MAX];
vector<go> v;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &board[i][j]);
      if (board[i][j] == 'W') {
        v.push_back({i, j});
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == '.') {
        board[i][j] = 'D';
      }
    }
  }
  int flag = 0;
  for (int i = 0; i < v.size(); i++) {
    int r = v[i].x;
    int c = v[i].y;
    for (int j = 0; j < 4; j++) {
      int nr = r + dy[j];
      int nc = c + dx[j];
      if (nr < 0 || nc < 0 || nr >= n || nc >= m)
        continue;
      if (board[nr][nc] == 'S') {
        flag = 1;
        break;
      }
    }
    if (flag == 1)
      break;
  }

  if (flag == 0) {
    cout << "1" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << board[i][j];
      }
      cout << endl;
    }
  } else {
    cout << "0" << endl;
  }
}
