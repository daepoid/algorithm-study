#include <bits/stdc++.h>
#define MAX 50
using namespace std;

int N, M;
int board[MAX][MAX];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};
int sum[3] = {0, 0, 0};
vector<pair<int, int>> cmds;
vector<int> list_board;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

void make_list_board() {
  int y = N / 2;
  int x = N / 2;
  int dir = 0;
  list_board.push_back(0);
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < i; k++) {
        if (!isvalid(y, x)) {
          printf("Error\n");
          return;
        }
        y += dy[dir];
        x += dx[dir];
        if (board[y][x] != 0) {
          list_board.push_back(board[y][x]);
        }
      }
      dir = (dir + 1) % 4;
    }
  }
}

void blizard(int idx) {
  int d = cmds[idx].first;
  int s = cmds[idx].second;
  int weight[5] = {0, 7, 3, 1, 5};

  for (int i = s; i > 0; i--) {
    int pos = 4 * i * i + (weight[d] - 4) * i;
    list_board.erase(list_board.begin() + pos);
  }
}

bool is_boomable() {
  int cnt = 1;
  for (int i = 1; i < list_board.size() - 1; i++) {
    if (list_board[i] == list_board[i + 1] && list_board[i] != 0) {
      cnt++;
      if (cnt >= 4) {
        return true;
      }
    } else if (list_board[i] != list_board[i + 1]) {
      cnt = 1;
    }
  }
  return false;
}

void boom_marbles() {
  int cnt = 1;
  vector<pair<int, int>> v;
  for (int i = list_board.size() - 1; i > 1; i--) {
    if (list_board[i] == list_board[i - 1]) {
      cnt++;
    } else if (list_board[i] != list_board[i - 1]) {
      if (cnt >= 4) {
        sum[list_board[i] - 1] += cnt;
        v.push_back({i, cnt});
      }
      cnt = 1;
    }
  }
  for (int i = 0; i < v.size(); i++) {
    int pos = v[i].first;
    list_board.erase(list_board.begin() + pos,
                     list_board.begin() + pos + v[i].second);
    // for (int j = 0; j < v[i].second; j++) {
    //   list_board.erase(list_board.begin() + v[i].first);
    // }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  for (int i = 0; i < M; i++) {
    int d, s;
    scanf("%d %d", &d, &s);
    cmds.push_back({d, s});
  }

  make_list_board();
  for (int i = 0; i < M; i++) {
    blizard(i);
    while (is_boomable()) {
      boom_marbles();
    }
  }
  printf("%d\n", sum[0] + sum[1] * 2 + sum[2] * 3);
}