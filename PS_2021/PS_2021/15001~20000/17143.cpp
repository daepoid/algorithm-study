#include <bits/stdc++.h>
#define MAX 101
using namespace std;

struct Shark {
  int s;
  int d;
  int z;
};

vector<int> answers;

int R, C, M;
int answer = 0;
int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, 1, -1};
vector<Shark> sharks[MAX][MAX];

bool comp(Shark a, Shark b) { return a.z < b.z; }

bool isvalid(int newy, int newx) {
  return 1 <= newy && newy <= R && 1 <= newx && newx <= C;
}

void fishing(int idx) {
  // 2. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다.
  // 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
  for (int i = 1; i < R + 1; i++) {
    if (sharks[i][idx].size() != 0) {
      answer += sharks[i][idx][0].z;
      answers.push_back(sharks[i][idx][0].z);
      sharks[i][idx].clear();
      break;
    }
  }
}

void move_shark() {
  // 이동
  for (int i = 1; i < R + 1; i++) {
    for (int j = 1; j < C + 1; j++) {
      if (sharks[i][j].size() == 0) {
        continue;
      }
      int y = i;
      int x = j;
      int s = sharks[i][j][0].s;
      int d = sharks[i][j][0].d;
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
      } else if (d >= 3) {
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
      Shark temp = {s, d, sharks[i][j][0].z};
      sharks[i][j].erase(sharks[i][j].begin());
      sharks[y][x].push_back(temp);
    }
  }
}

void eat_small_fishes() {
  // 포식
  for (int i = 1; i < R + 1; i++) {
    for (int j = 1; j < C + 1; j++) {
      if (sharks[i][j].size() > 1) {
        sort(sharks[i][j].begin(), sharks[i][j].end(), comp);
        Shark temp = sharks[i][j][sharks[i][j].size() - 1];
        sharks[i][j].clear();
        sharks[i][j].push_back(temp);

        // Shark temp = {-1, -1, -1};
        // for (int k = 0; k < sharks[i][j].size(); k++) {
        //   if (comp(temp, sharks[i][j][k])) {
        //     temp = sharks[i][j][k];
        //   }
        // }
        // sharks[i][j].clear();
        // sharks[i][j].push_back(temp);
      }
    }
  }
}

int main() {
  int r, c, s, d, z;
  scanf("%d %d %d", &R, &C, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
    Shark temp_shark = {s, d, z};
    sharks[r][c].push_back(temp_shark);
  }
  for (int i = 1; i < C + 1; i++) {
    fishing(i);
    move_shark();
    eat_small_fishes();
  }
  printf("%d\n", answer);
}