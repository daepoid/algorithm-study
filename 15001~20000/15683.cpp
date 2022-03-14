#include <bits/stdc++.h>
#define MAX 8
using namespace std;

int N, M, answer = 2100000000;
int board[MAX][MAX], covered_board[MAX][MAX];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
vector<pair<pair<int, int>, pair<int, int>>> v;

void copy_board() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      covered_board[i][j] = board[i][j];
    }
  }
}

void cover(int y, int x, int dir) {
  int start, end, w, idx;
  if (dir == 0) {
    start = x + 1;
    idx = y;
    end = M;
    w = 1;
  } else if (dir == 1) {
    start = x - 1;
    idx = y;
    end = M;
    w = -1;
  } else if (dir == 2) {
    start = y + 1;
    idx = x;
    end = N;
    w = 1;
  } else if (dir == 3) {
    start = y - 1;
    idx = x;
    end = N;
    w = -1;
  }

  for (start; (0 <= start) && (start < end); start += w) {
    if (dir < 2) {
      if (covered_board[idx][start] == 6) {
        break;
      }
      if (1 <= covered_board[idx][start] && covered_board[idx][start] <= 5) {
        continue;
      }
      covered_board[idx][start] = -1;
    } else {
      if (covered_board[start][idx] == 6) {
        break;
      }
      if (1 <= covered_board[start][idx] && covered_board[start][idx] <= 5) {
        continue;
      }
      covered_board[start][idx] = -1;
    }
  }
}

void check() {
  copy_board();
  for (int i = 0; i < v.size(); i++) {
    if (v[i].second.first == 1) {
      cover(v[i].first.first, v[i].first.second, v[i].second.second);
    } else if (v[i].second.first == 2) {
      if (v[i].second.second == 0 || v[i].second.second == 1) {
        cover(v[i].first.first, v[i].first.second, 0);
        cover(v[i].first.first, v[i].first.second, 1);
      } else if (v[i].second.second == 2 || v[i].second.second == 3) {
        cover(v[i].first.first, v[i].first.second, 2);
        cover(v[i].first.first, v[i].first.second, 3);
      }
    } else if (v[i].second.first == 3) {
      if (v[i].second.second == 0) {
        cover(v[i].first.first, v[i].first.second, 0);
        cover(v[i].first.first, v[i].first.second, 3);
      } else if (v[i].second.second == 1) {
        cover(v[i].first.first, v[i].first.second, 0);
        cover(v[i].first.first, v[i].first.second, 2);
      } else if (v[i].second.second == 2) {
        cover(v[i].first.first, v[i].first.second, 1);
        cover(v[i].first.first, v[i].first.second, 2);
      } else if (v[i].second.second == 3) {
        cover(v[i].first.first, v[i].first.second, 1);
        cover(v[i].first.first, v[i].first.second, 3);
      }
    } else if (v[i].second.first == 4) {
      if (v[i].second.second == 0) {
        cover(v[i].first.first, v[i].first.second, 0);
        cover(v[i].first.first, v[i].first.second, 1);
        cover(v[i].first.first, v[i].first.second, 3);
      } else if (v[i].second.second == 1) {
        cover(v[i].first.first, v[i].first.second, 0);
        cover(v[i].first.first, v[i].first.second, 2);
        cover(v[i].first.first, v[i].first.second, 3);
      } else if (v[i].second.second == 2) {
        cover(v[i].first.first, v[i].first.second, 0);
        cover(v[i].first.first, v[i].first.second, 1);
        cover(v[i].first.first, v[i].first.second, 2);
      } else if (v[i].second.second == 3) {
        cover(v[i].first.first, v[i].first.second, 1);
        cover(v[i].first.first, v[i].first.second, 2);
        cover(v[i].first.first, v[i].first.second, 3);
      }
    } else if (v[i].second.first == 5) {
      cover(v[i].first.first, v[i].first.second, 0);
      cover(v[i].first.first, v[i].first.second, 1);
      cover(v[i].first.first, v[i].first.second, 2);
      cover(v[i].first.first, v[i].first.second, 3);
    }
  }
}

int count_deadzone() {
  int sum = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (covered_board[i][j] == 0) {
        sum++;
      }
    }
  }
  return sum;
}

void sol(int cnt) {
  if (cnt == v.size()) {
    check();
    answer = min(answer, count_deadzone());
    return;
  }

  v[cnt].second.second = 0;
  sol(cnt + 1);

  v[cnt].second.second = 1;
  sol(cnt + 1);

  v[cnt].second.second = 2;
  sol(cnt + 1);

  v[cnt].second.second = 3;
  sol(cnt + 1);
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &board[i][j]);
      if (1 <= board[i][j] && board[i][j] <= 5) {
        v.push_back(make_pair(make_pair(i, j), make_pair(board[i][j], -1)));
      }
    }
  }
  sol(0);
  printf("%d\n", answer);
}