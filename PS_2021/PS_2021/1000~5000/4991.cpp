#include <bits/stdc++.h>
#define MAX 21
using namespace std;

int W, H;
int board[MAX][MAX], dist[MAX][MAX];
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < H && 0 <= newx && newx < W;
}

void bfs(int y, int x) {
  bool visited[MAX][MAX] = {
      false,
  };
  queue<pair<int, int>> q;
  visited[y][x] = true;
  q.push(make_pair(y, x));

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];

      if (!isvalid(newy, newx)) {
        continue;
      } else if (visited[newy][newx]) {
        continue;
      } else if (board[newy][newx] == -1) {
        continue;
      }

      visited[newy][newx] = true;
      q.push(make_pair(newy, newx));
      dist[newy][newx] = dist[y][x] + 1;
    }
  }
}

int main() {
  char c;
  while (true) {
    scanf("%d %d", &W, &H);
    if (W == 0 && H == 0) {
      return 0;
    }
    vector<pair<int, int>> v(1);
    memset(board, 0, sizeof(board));

    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        scanf(" %c", &c);
        if (c == '*') {
          v.push_back(make_pair(i, j));
        } else if (c == 'x') {
          board[i][j] = -1;
        } else if (c == 'o') {
          v[0] = make_pair(i, j);
        }
      }
    }
    int result[MAX][MAX] = {
        0,
    };
    for (int i = 0; i < v.size(); i++) {
      memset(dist, 0, sizeof(dist));
      bfs(v[i].first, v[i].second);

      for (int j = 0; j < v.size(); j++) {
        result[i][j] = dist[v[j].first][v[j].second];
      }
    }

    vector<int> arr(v.size() - 1);
    for (int i = 0; i < v.size() - 1; i++) {
      arr[i] = i + 1;
    }
    int answer = 2100000000;
    bool flag = true;
    do {
      int sum = result[0][arr[0]];
      if (sum == 0) {
        flag = false;
        break;
      }
      for (int i = 0; i < v.size() - 2; i++) {
        sum += result[arr[i]][arr[i + 1]];
      }
      answer = min(answer, sum);
    } while (next_permutation(arr.begin(), arr.end()));
    if (!flag) {
      printf("-1\n");
    } else {
      printf("%d\n", answer);
    }
  }
}