#include <bits/stdc++.h>
#define MAX 50
using namespace std;

struct COORD {
  int y;
  int x;
};

int N, M, Answer, Marble[4];
int board[MAX][MAX];
int N_MAP[MAX][MAX];
bool Delete[MAX * MAX];
COORD Shark;
COORD Coord[MAX * MAX];
vector<pair<int, int>> cmds;

int dy[] = {0, -1, 1, 0, 0};
int dx[] = {0, 0, 0, -1, 1};

int Change_Dir(int dir) {
  if (dir == 1)
    return 3;
  if (dir == 2)
    return 4;
  if (dir == 3)
    return 2;
  if (dir == 4)
    return 1;
}

void build_board() {
  int y = N / 2;
  int x = N / 2;
  int Move_Cnt = 1;
  int Num = 0;
  int dir = 3;

  Shark = {y, x};
  N_MAP[y][x] = Num;
  Coord[Num++] = {y, x};
  while (1) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < Move_Cnt; j++) {
        y += dy[dir];
        x += dx[dir];
        N_MAP[y][x] = Num;
        Coord[Num++] = {y, x};
      }
      dir = Change_Dir(dir);
    }
    Move_Cnt++;

    if (Move_Cnt == N) {
      for (int j = 0; j < Move_Cnt; j++) {
        y += dy[dir];
        x += dx[dir];
        N_MAP[y][x] = Num;
        Coord[Num++] = {y, x};
      }
      break;
    }
  }
}

void blizard(int Idx) {
  memset(Delete, false, sizeof(Delete));
  int dir = cmds[Idx].first;
  int K = cmds[Idx].second;

  int y = Shark.y;
  int x = Shark.x;
  for (int i = 0; i < K; i++) {
    y += dy[dir];
    x += dx[dir];
    Delete[N_MAP[y][x]] = true;
  }
}

void move_marbles() {
  bool Flag = false;
  int cnt = 0;
  for (int i = 1; i < N * N; i++) {
    if (Delete[i] == true) {
      Flag = true;
      cnt++;
    } else {
      if (board[Coord[i].y][Coord[i].x] == 0) {
        for (int j = 1; j <= cnt; j++)
          board[Coord[i - j].y][Coord[i - j].x] = 0;
        Flag = false;
        break;
      } else
        board[Coord[i - cnt].y][Coord[i - cnt].x] =
            board[Coord[i].y][Coord[i].x];
    }
  }

  if (Flag == true) {
    int i = (N * N) - 1;
    for (int j = 0; j < cnt; j++, i--)
      board[Coord[i].y][Coord[i].x] = 0;
  }
}

bool Destroy_Sequence_Marble() {
  memset(Delete, false, sizeof(Delete));

  bool Flag = false;
  int Cur_Marble = board[Coord[1].y][Coord[1].x];
  int Sequence_Cnt = 1;
  int Start_Num = 1;
  int Num;
  for (Num = 2; Num < N * N; Num++) {
    int Next_Marble = board[Coord[Num].y][Coord[Num].x];
    if (Next_Marble == 0)
      break;

    if (Cur_Marble == Next_Marble)
      Sequence_Cnt++;
    else {
      if (Sequence_Cnt >= 4) {
        Flag = true;
        for (int i = Start_Num; i < Num; i++)
          Delete[i] = true;
        Marble[Cur_Marble] += Sequence_Cnt;
      }

      Cur_Marble = Next_Marble;
      Sequence_Cnt = 1;
      Start_Num = Num;
    }
  }

  if (Sequence_Cnt >= 4) {
    Flag = true;
    for (int i = Start_Num; i < Num; i++)
      Delete[i] = true;
    Marble[Cur_Marble] += Sequence_Cnt;
  }
  return Flag;
}

void rebuild_board() {
  int New_MAP[MAX][MAX] = {
      0,
  };
  int Cur_Marble = board[Coord[1].y][Coord[1].x];
  int cnt = 1;
  int Pos_Num = 1;
  bool Flag = true;
  for (int Num = 2; Num < N * N; Num++) {
    if (Pos_Num >= N * N) {
      Flag = false;
      break;
    }

    int Next_Marble = board[Coord[Num].y][Coord[Num].x];
    if (Next_Marble == 0)
      break;
    if (Cur_Marble == Next_Marble)
      cnt++;
    else {
      New_MAP[Coord[Pos_Num].y][Coord[Pos_Num].x] = cnt;
      New_MAP[Coord[Pos_Num + 1].y][Coord[Pos_Num + 1].x] = Cur_Marble;
      Cur_Marble = Next_Marble;
      cnt = 1;
      Pos_Num += 2;
    }
  }
  if (Flag == true) {
    if (Pos_Num != 1) {
      New_MAP[Coord[Pos_Num].y][Coord[Pos_Num].x] = cnt;
      New_MAP[Coord[Pos_Num + 1].y][Coord[Pos_Num + 1].x] = Cur_Marble;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      board[i][j] = New_MAP[i][j];
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
    cmds.push_back(make_pair(a, b));
  }

  build_board();
  for (int i = 0; i < M; i++) {
    blizard(i);
    move_marbles();

    while (1) {
      if (Destroy_Sequence_Marble() == false)
        break;
      move_marbles();
    }
    rebuild_board();
  }
  Answer = Marble[1] + (2 * Marble[2]) + (3 * Marble[3]);
  cout << Answer << endl;

  return 0;
}