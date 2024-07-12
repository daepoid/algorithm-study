#include <bits/stdc++.h>
#define MAX 21
using namespace std;

struct STUDENT {
  int num;
  int friends[4];
};

int N, answer;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int board[MAX][MAX];
STUDENT students_arr[MAX * MAX + 1];
vector<STUDENT> students;

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < N && 0 <= newx && newx < N;
}

int cnt_near_students(int y, int x, int idx) {
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    int newy = y + dy[i];
    int newx = x + dx[i];
    if (!isvalid(newy, newx)) {
      continue;
    }

    for (int j = 0; j < 4; j++) {
      if (board[newy][newx] == students[idx].friends[j]) {
        cnt++;
        break;
      }
    }
  }
  return cnt;
}

int cnt_zero_seats(int y, int x) {
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    int newy = y + dy[i];
    int newx = x + dx[i];

    if (!isvalid(newy, newx)) {
      continue;
    }
    if (board[newy][newx] == 0) {
      cnt++;
    }
  }
  return cnt;
}

void set_seats(int idx) {
  int max_near = -1;
  pair<int, int> max_pos = {-1, -1};
  // 1번 조건
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] != 0) {
        continue;
      }
      int now_near = cnt_near_students(i, j, idx);
      if (max_near < now_near) {
        max_near = now_near;
        max_pos = {i, j};
      } else if (max_near == now_near) {
        // 2번 조건
        int max_pos_zero = cnt_zero_seats(max_pos.first, max_pos.second);
        int now_zero = cnt_zero_seats(i, j);
        if (max_pos_zero < now_zero) {
          max_near = now_near;
          max_pos = {i, j};
        } else if (max_pos_zero == now_zero) {
          // 3번 조건
          if (max_pos.first > i) {
            max_near = now_near;
            max_pos = {i, j};
          } else if (max_pos.first == i) {
            if (max_pos.second > j) {
              max_near = now_near;
              max_pos = {i, j};
            }
          }
        }
      }
    }
  }
  board[max_pos.first][max_pos.second] = students[idx].num;
}

void sum_friendship() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int cnt = cnt_near_students(i, j, students_arr[board[i][j]].num);
      answer = answer + pow(10, cnt - 1);
    }
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N * N; i++) {
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    students.push_back({a, b, c, d, e});
    students_arr[a].num = i;
    students_arr[a].friends[0] = b;
    students_arr[a].friends[1] = c;
    students_arr[a].friends[2] = d;
    students_arr[a].friends[3] = e;
    set_seats(i);
  }
  sum_friendship();
  printf("%d\n", answer);
}