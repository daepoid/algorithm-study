#include <bits/stdc++.h>
#define MAX 7
using namespace std;

int N, M;
int input_board[MAX][MAX];
int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};
int sum[] = {0, 0, 0, 0};
vector<pair<int, int>> cmds;
vector<int> board;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

void make_list_board() {
  int y = N / 2;
  int x = N / 2;
  int dir = 0;
  board.push_back(0);
  for (int i = 1; i < N + 1; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < i; k++) {
        y += dy[dir];
        x += dx[dir];
        if (!isvalid(y, x)) {
          return;
        }
        if (input_board[y][x] != 0) {
          board.push_back(input_board[y][x]);
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
    board.erase(board.begin() + pos);
  }
}

bool is_boomable() {
  int cnt = 1;
  for (int i = 1; i < board.size() - 1; i++) {
    if (board[i] == board[i + 1]) {
      cnt++;
      if (cnt == 4) {
        return true;
      }
    } else {
      cnt = 1;
    }
  }
  return false;
}

void boom_marbles() {
  int cnt = 1;
  vector<pair<int, int>> v;
  for (int i = board.size() - 1; i > 1; i--) {
    if (board[i] == board[i - 1]) {
      cnt++;
    } else if (board[i] != board[i - 1]) {
      if (cnt >= 4) {
        sum[board[i]] += cnt;
        v.push_back({i, cnt});
      }
      cnt = 1;
    }
  }
  if (cnt >= 4) {
    sum[board[1]] += cnt;
    v.push_back({1, cnt});
  }
  for (int i = 0; i < v.size(); i++) {
    int pos = v[i].first;
    for (int j = 0; j < v[i].second; j++) {
      board.erase(board.begin() + pos);
    }
  }
}

void remake_board() {
  vector<int> temp_board;
  temp_board.push_back(0);

  int cnt = 1;
  for (int i = 1; i < board.size() - 1; i++) {
    if (board[i] == board[i + 1]) {
      cnt++;
    } else {
      temp_board.push_back(cnt);
      temp_board.push_back(board[i]);
      cnt = 1;
    }
  }
  temp_board.push_back(cnt);
  temp_board.push_back(board[board.size() - 1]);

  if (temp_board.size() >= N * N) {
    temp_board.erase(temp_board.begin() + N * N, temp_board.end());
  }

  board = temp_board;
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &input_board[i][j]);
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
    remake_board();
  }

  printf("%d\n", sum[1] + sum[2] * 2 + sum[3] * 3);
  return 0;
}