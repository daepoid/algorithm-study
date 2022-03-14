#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int N, M, T, total, answer = 0;
int circle[MAX][MAX];
bool visited[MAX][MAX];

void turn_circle(int idx, int dir, int k) {
  int copied_circle[MAX][MAX];
  memcpy(copied_circle, circle, sizeof(circle));
  if (dir == 0) {
    for (int i = 0; i < M; i++) {
      int val = circle[idx][i];
      int pos = (i + k) % M;
      copied_circle[idx][pos] = val;
    }
  } else {
    for (int i = 0; i < M; i++) {
      int val = circle[idx][i];
      int temp = k % M;
      int pos = i - temp;
      if (pos < 0) {
        pos += M;
      }
      copied_circle[idx][pos] = val;
    }
  }
  memcpy(circle, copied_circle, sizeof(copied_circle));
}

bool bfs(int a, int b) {
  queue<pair<int, int>> q;
  vector<pair<int, int>> v;
  q.push({a, b});
  v.push_back({a, b});
  visited[a][b] = true;

  while (!q.empty()) {
    int circle_num = q.front().first;
    int idx = q.front().second;
    q.pop();

    int l_idx = idx - 1;
    int r_idx = idx + 1;
    int inner_circle = circle_num - 1;
    int outter_circle = circle_num + 1;

    if (l_idx < 0) {
      l_idx = M - 1;
    }
    if (r_idx >= M) {
      r_idx = r_idx % M;
    }
    if (circle[circle_num][idx] == circle[circle_num][l_idx]) {
      if (!visited[circle_num][l_idx]) {
        visited[circle_num][l_idx] = true;
        q.push({circle_num, l_idx});
        v.push_back({circle_num, l_idx});
      }
    }
    if (circle[circle_num][idx] == circle[circle_num][r_idx]) {
      if (!visited[circle_num][r_idx]) {
        visited[circle_num][r_idx] = true;
        q.push({circle_num, r_idx});
        v.push_back({circle_num, r_idx});
      }
    }
    if (inner_circle > 0) {
      if (circle[circle_num][idx] == circle[inner_circle][idx]) {
        if (visited[inner_circle][idx]) {
          q.push({inner_circle, idx});
          v.push_back({inner_circle, idx});
        }
      }
    }
    if (outter_circle <= N) {
      if (circle[circle_num][idx] == circle[outter_circle][idx]) {
        if (visited[outter_circle][idx]) {
          q.push({outter_circle, idx});
          v.push_back({outter_circle, idx});
        }
      }
    }
  }
  if (v.size() == 1) {
    return false;
  } else {
    for (int i = 0; i < v.size(); i++) {
      int y = v[i].first;
      int x = v[i].second;
      circle[y][x] = 0;
    }
    return true;
  }
}

bool check_circle() {
  memset(visited, false, sizeof(visited));
  bool flag = false;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < M; j++) {
      if (!visited[i][j] && circle[i][j] != 0) {
        if (bfs(i, j)) {
          flag = true;
        }
      }
    }
  }
  return flag;
}

pair<int, int> calculate() {
  int sum = 0;
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < M; j++) {
      sum += circle[i][j];
      if (circle[i][j] != 0) {
        cnt++;
      }
    }
  }
  return {sum, cnt};
}

void change_val(int avg) {
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < M; j++) {
      if (circle[i][j] == 0) {
        continue;
      }
      if ((double)(circle[i][j]) > avg) {
        circle[i][j]--;
      } else if ((double)(circle[i][j]) < avg) {
        circle[i][j]++;
      }
    }
  }
}

int main() {
  scanf("%d %d %d", &N, &M, &T);
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &circle[i][j]);
    }
  }
  total = N * M;

  for (int i = 0; i < T; i++) {
    int num, dir, k;
    scanf("%d %d %d", &num, &dir, &k);
    for (int j = num; j <= N; j += num) {
      turn_circle(j, dir, k);
    }
    if (!check_circle()) {
      pair<int, int> temp = calculate();
      double avg = (double)(temp.first) / temp.second;
      change_val(avg);
    }
  }
  printf("%d\n", calculate().first);
}