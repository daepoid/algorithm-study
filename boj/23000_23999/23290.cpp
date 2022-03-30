#include <bits/stdc++.h>
#define MAX 4
using namespace std;

struct Fish {
  int x;
  int y;
  int dir;
};

int M, S;
int shark_x, shark_y;
vector<Fish> fishes[MAX][MAX];
vector<Fish> copied_fishes[MAX][MAX];

int smell[MAX][MAX];
int route[4], temp_route[4];
// 서, 북서, 북, 북동, 동, 남동, 남, 남서
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int sdx[4] = {-1, 0, 1, 0};
int sdy[4] = {0, -1, 0, 1};

int now_max = -1;

void copy_fishes() {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      copied_fishes[i][j] = fishes[i][j];
    }
  }
}

bool is_valid(int newx, int newy) {
  return 0 <= newx && newx < MAX && 0 <= newy && newy < MAX;
}

bool is_shark(int newx, int newy) { return newx == shark_x && newy == shark_y; }

bool has_smell(int newx, int newy) { return smell[newx][newy] > 0; }

void move_fishes() {
  vector<Fish> next_fishes[MAX][MAX];
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      for (int k = 0; k < fishes[i][j].size(); k++) {
        int x = fishes[i][j][k].x;
        int y = fishes[i][j][k].y;
        int dir = fishes[i][j][k].dir;

        int newx = x;
        int newy = y;
        int next_dir = dir;
        for (int l = 0; l < 8; l++) {
          newx = x + dx[next_dir];
          newy = y + dy[next_dir];
          if (is_valid(newx, newy) && !is_shark(newx, newy) &&
              !has_smell(newx, newy)) {
            x = newx;
            y = newy;
            dir = next_dir;
            break;
          }
          next_dir = (next_dir + 7) % 8;
        }

        Fish temp = {x, y, dir};
        next_fishes[x][y].push_back(temp);
      }
    }
  }

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      fishes[i][j] = next_fishes[i][j];
    }
  }
}

int count_eat_fish() {
  bool visited[MAX][MAX] = {
      false,
  };
  int x = shark_x;
  int y = shark_y;

  int eat_count = 0;

  for (int i = 0; i < 3; i++) {
    int dir = temp_route[i];
    int newx = x + sdx[dir];
    int newy = y + sdy[dir];

    if (!is_valid(newx, newy)) {
      return -1;
    }

    if (!visited[newx][newy]) {
      visited[newx][newy] = true;
      eat_count += fishes[newx][newy].size();
    }
    x = newx;
    y = newy;
  }
  return eat_count;
}

void find_shark_route(int move) {
  if (move == 3) {
    int eat_count = count_eat_fish();

    if (eat_count > now_max) {
      for (int i = 0; i < 3; i++) {
        route[i] = temp_route[i];
      }
      now_max = eat_count;
    }
    return;
  }

  for (int i = 0; i < 4; i++) {
    temp_route[move] = i;
    find_shark_route(move + 1);
  }
}

void eat_fishes() {
  for (int i = 0; i < 3; i++) {
    int dir = route[i];
    shark_x += sdx[dir];
    shark_y += sdy[dir];

    if (fishes[shark_x][shark_y].size() != 0) {
      smell[shark_x][shark_y] = 3;
      fishes[shark_x][shark_y].clear();
    }
  }
}

void move_shark() {
  now_max = -1;
  find_shark_route(0);
  eat_fishes();
}

void remove_smell() {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      smell[i][j] = max(smell[i][j] - 1, 0);
    }
  }
}

void paste_fishes() {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      for (int k = 0; k < copied_fishes[i][j].size(); k++) {
        fishes[i][j].push_back(copied_fishes[i][j][k]);
      }
    }
  }
}

int count_fishes() {
  int count = 0;
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      count += fishes[i][j].size();
    }
  }
  return count;
}

int main() {
  scanf("%d %d", &M, &S);
  int x, y, d;
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &x, &y, &d);
    fishes[x - 1][y - 1].push_back({x - 1, y - 1, d - 1});
  }
  scanf("%d %d", &shark_x, &shark_y);

  shark_x--;
  shark_y--;

  for (int i = 0; i < S; i++) {
    copy_fishes();
    move_fishes();
    move_shark();
    remove_smell();
    paste_fishes();
  }
  printf("%d\n", count_fishes());
  return 0;
}