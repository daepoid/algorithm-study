#include <bits/stdc++.h>
#define MAX 50
using namespace std;

struct POS {
  int y;
  int x;
};

int N, M, Answer, boom_sum[4];
int board[MAX][MAX];
int num_board[MAX][MAX];
bool isdeleted[MAX * MAX];
POS shark;
POS list_board[MAX * MAX];
vector<pair<int, int>> cmds;

int dy[] = {0, -1, 1, 0, 0};
int dx[] = {0, 0, 0, -1, 1};

int change_dir(int dir) {
  if (dir == 1) {
    return 3;
  } else if (dir == 2) {
    return 4;
  } else if (dir == 3) {
    return 2;
  } else if (dir == 4) {
    return 1;
  }
  return -1;
}

void build_board() {
  int y = N / 2;
  int x = N / 2;
  int s = 1;
  int num = 0;
  int dir = 3;

  shark = {y, x};
  num_board[y][x] = num;
  list_board[num++] = {y, x};
  while (1) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < s; j++) {
        y += dy[dir];
        x += dx[dir];
        num_board[y][x] = num;
        list_board[num++] = {y, x};
      }
      dir = change_dir(dir);
    }
    s++;

    if (s == N) {
      for (int j = 0; j < s; j++) {
        y += dy[dir];
        x += dx[dir];
        num_board[y][x] = num;
        list_board[num++] = {y, x};
      }
      break;
    }
  }
}

void blizard(int Idx) {
  memset(isdeleted, false, sizeof(isdeleted));
  int dir = cmds[Idx].first;
  int s = cmds[Idx].second;

  int y = shark.y;
  int x = shark.x;
  for (int i = 0; i < s; i++) {
    y += dy[dir];
    x += dx[dir];
    isdeleted[num_board[y][x]] = true;
  }
}

void move_marbles() {
  bool flag = false;
  int cnt = 0;
  for (int i = 1; i < N * N; i++) {
    if (isdeleted[i]) {
      flag = true;
      cnt++;
    } else {
      if (board[list_board[i].y][list_board[i].x] == 0) {
        for (int j = 1; j <= cnt; j++) {
          board[list_board[i - j].y][list_board[i - j].x] = 0;
        }
        flag = false;
        break;
      } else
        board[list_board[i - cnt].y][list_board[i - cnt].x] =
            board[list_board[i].y][list_board[i].x];
    }
  }

  if (flag) {
    int i = (N * N) - 1;
    for (int j = 0; j < cnt; j++, i--) {
      board[list_board[i].y][list_board[i].x] = 0;
    }
  }
}

bool boom_marbles() {
  memset(isdeleted, false, sizeof(isdeleted));

  bool flag = false;
  int now_num = board[list_board[1].y][list_board[1].x];
  int cnt = 1;
  int start_num = 1;
  int num;
  for (num = 2; num < N * N; num++) {
    int nwxt_num = board[list_board[num].y][list_board[num].x];
    if (nwxt_num == 0) {
      break;
    }

    if (now_num == nwxt_num) {
      cnt++;
    } else {
      if (cnt >= 4) {
        flag = true;
        for (int i = start_num; i < num; i++) {
          isdeleted[i] = true;
        }
        boom_sum[now_num] += cnt;
      }

      now_num = nwxt_num;
      cnt = 1;
      start_num = num;
    }
  }

  if (cnt >= 4) {
    flag = true;
    for (int i = start_num; i < num; i++) {
      isdeleted[i] = true;
    }
    boom_sum[now_num] += cnt;
  }
  return flag;
}

void remake_board() {
  int new_board[MAX][MAX] = {
      0,
  };
  int now_num = board[list_board[1].y][list_board[1].x];
  int cnt = 1;
  int pos_num = 1;
  bool flag = true;
  for (int num = 2; num < N * N; num++) {
    if (pos_num >= N * N) {
      flag = false;
      break;
    }

    int nwxt_num = board[list_board[num].y][list_board[num].x];
    if (nwxt_num == 0) {
      break;
    }
    if (now_num == nwxt_num) {
      cnt++;
    } else {
      new_board[list_board[pos_num].y][list_board[pos_num].x] = cnt;
      new_board[list_board[pos_num + 1].y][list_board[pos_num + 1].x] = now_num;
      now_num = nwxt_num;
      cnt = 1;
      pos_num += 2;
    }
  }
  if (flag == true) {
    if (pos_num != 1) {
      new_board[list_board[pos_num].y][list_board[pos_num].x] = cnt;
      new_board[list_board[pos_num + 1].y][list_board[pos_num + 1].x] = now_num;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      board[i][j] = new_board[i][j];
    }
  }
}

int main(void) {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  for (int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    cmds.push_back({a, b});
  }

  build_board();
  for (int i = 0; i < M; i++) {
    blizard(i);
    move_marbles();

    while (true) {
      if (!boom_marbles()) {
        break;
      }
      move_marbles();
    }
    remake_board();
  }

  printf("%d\n", boom_sum[1] + (2 * boom_sum[2]) + (3 * boom_sum[3]));
  return 0;
}