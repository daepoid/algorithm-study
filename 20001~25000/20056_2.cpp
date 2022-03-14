#include <bits/stdc++.h>
#define MAX 51
using namespace std;

struct FIREBALL {
  int y;
  int x;
  int m;
  int s;
  int d;
};

int N, M, K, answer = 0;
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<FIREBALL> board[MAX][MAX];
vector<FIREBALL> fireballs;

void move_fireballs() {
  // 1. 모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      board[i][j].clear();
    }
  }
  for (int i = 0; i < fireballs.size(); i++) {
    FIREBALL temp = fireballs[i];
    int newy = temp.y + dy[temp.d] * (temp.s % N);
    int newx = temp.x + dx[temp.d] * (temp.s % N);
    if (newy > N) {
      newy -= N;
    }
    if (newx > N) {
      newx -= N;
    }
    if (newy < 1) {
      newy += N;
    }
    if (newx < 1) {
      newx += N;
    }
    board[newy][newx].push_back({newy, newx, temp.m, temp.s, temp.d});
    fireballs[i].y = newy;
    fireballs[i].x = newx;
  }
}

void sum_fireballs() {
  vector<FIREBALL> temp;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (board[i][j].size() == 0) {
        continue;
      }
      if (board[i][j].size() == 1) {
        temp.push_back(board[i][j][0]);
        continue;
      }
      /*
      2. 이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸에서는 다음과 같은
      일이 일어난다.
      */
      int newm = 0;
      int news = 0;
      int size = board[i][j].size();
      int even_cnt = 0;

      for (int k = 0; k < size; k++) {
        newm += board[i][j][k].m;
        news += board[i][j][k].s;
        if (board[i][j][k].d % 2 == 0) {
          even_cnt++;
        }
      }
      newm /= 5;
      news /= size;
      if (newm == 0) {
        continue;
      }
      if (even_cnt == 0 || even_cnt == size) {
        for (int k = 0; k < 4; k++) {
          temp.push_back({i, j, newm, news, 2 * k});
        }
      } else {
        for (int k = 0; k < 4; k++) {
          temp.push_back({i, j, newm, news, 2 * k + 1});
        }
      }
    }
  }
  fireballs = temp;
}

int main() {
  scanf("%d %d %d", &N, &M, &K);
  for (int i = 0; i < M; i++) {
    int r, c, m, s, d;
    scanf("%d %d %d %d %d", &r, &c, &m, &s, &d);
    fireballs.push_back({r, c, m, s, d});
    board[r][c].push_back({r, c, m, s, d});
  }
  for (int i = 0; i < K; i++) {
    move_fireballs();
    sum_fireballs();
  }
  for (int i = 0; i < fireballs.size(); i++) {
    answer += fireballs[i].m;
  }
  printf("%d\n", answer);
}