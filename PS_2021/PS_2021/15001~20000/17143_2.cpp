#include <bits/stdc++.h>
#define MAX 101
using namespace std;

struct Shark {
  int r;
  int c;
  int s;
  int d;
  int z;
  int num;
};

int R, C, M;
int answer = 0;
int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, 1, -1};
vector<int> board[MAX][MAX];
vector<Shark> sharks;

bool comp(int a, int b) { return sharks[a].z > sharks[b].z; }

bool check() {
  for (int i = 0; i < sharks.size(); i++) {
    if (sharks[i].z != 0) {
      return false;
    }
  }
  return true;
}

void fishing(int idx) {
  for (int i = 1; i < R + 1; i++) {
    if (board[i][idx].size() != 0) {
      answer += sharks[board[i][idx][0]].z;
      sharks[board[i][idx][0]].z = 0;
      board[i][idx].clear();
      break;
    }
  }
}

void move_shark() {
  for (int i = 0; i < sharks.size(); i++) {
    if (sharks[i].z == 0) {
      continue;
    }
    board[sharks[i].r][sharks[i].c].clear();
  }

  for (int i = 0; i < sharks.size(); i++) {
    if (sharks[i].z == 0) {
      continue;
    }
    int y = sharks[i].r;
    int x = sharks[i].c;
    int s = sharks[i].s;
    int d = sharks[i].d;
    if (d <= 2) {
      int rotate = (R - 1) * 2;
      if (s >= rotate) {
        s %= rotate;
      }
      for (int j = 0; j < s; j++) {
        int newy = y + dy[d];
        int newx = x + dx[d];
        if (newy < 1) {
          d = 2;
          newy += 2;
        }
        if (newy > R) {
          d = 1;
          newy -= 2;
        }
        y = newy;
        x = newx;
      }
    } else {
      int rotate = (C - 1) * 2;
      if (s >= rotate) {
        s %= rotate;
      }
      for (int j = 0; j < s; j++) {
        int newy = y + dy[d];
        int newx = x + dx[d];
        if (newx < 1) {
          d = 3;
          newx += 2;
        }
        if (newx > C) {
          d = 4;
          newx -= 2;
        }
        y = newy;
        x = newx;
      }
    }
    sharks[i].r = y;
    sharks[i].c = x;
    sharks[i].d = d;
    board[y][x].push_back(i);
  }
}

void eat_small_shark() {
  for (int i = 1; i < R + 1; i++) {
    for (int j = 1; j < C + 1; j++) {
      if (board[i][j].size() > 1) {
        sort(board[i][j].begin(), board[i][j].end(), comp);
        int idx = board[i][j][0];
        for (int k = 1; k < board[i][j].size(); k++) {
          sharks[board[i][j][k]].z = 0;
          sharks[board[i][j][k]].r = -1;
          sharks[board[i][j][k]].c = -1;
        }
        board[i][j].clear();
        board[i][j].push_back(sharks[idx].num);
      }
    }
  }
}

int main() {
  int r, c, s, d, z;
  scanf("%d %d %d", &R, &C, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
    Shark temp_shark = {r, c, s, d, z, i};
    sharks.push_back(temp_shark);
    board[r][c].push_back(i);
  }

  if (M == 0) {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i < C + 1; i++) {
    if (check()) {
      continue;
    }
    fishing(i);
    move_shark();
    eat_small_shark();
  }
  printf("%d\n", answer);
}