#include <bits/stdc++.h>
#define MAX 20
using namespace std;

int n, board[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
bool visited[MAX][MAX];

typedef struct {
  int y;
  int x;
  int size;
  int eats;
  int time;
} Shark;

typedef struct {
  int y;
  int x;
  int distance;
} Fish;

Shark shark;
vector<Fish> fishes;

bool comp(Fish a, Fish b) {
  if (a.distance < b.distance) {
    return true;
  } else if (a.distance > b.distance) {
    return false;
  }

  if (a.y < b.y) {
    return true;
  } else if (a.y > b.y) {
    return false;
  }

  if (a.x < b.x) {
    return true;
  } else {
    return false;
  }
}

bool isvalid(int newy, int newx) {
  return 0 <= newy && newy < n && 0 <= newx && newx < n;
}

void bfs(int y, int x) {
  memset(visited, false, sizeof(visited));
  queue<pair<pair<int, int>, int>> q;
  int dist = 0;
  q.push(make_pair(make_pair(y, x), dist));
  visited[y][x] = true;

  while (!q.empty()) {
    y = q.front().first.first;
    x = q.front().first.second;
    dist = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newy = y + dy[i];
      int newx = x + dx[i];

      if (!isvalid(newy, newx) || visited[newy][newx] ||
          board[newy][newx] > shark.size) {
        continue;
      }

      visited[newy][newx] = true;
      q.push(make_pair(make_pair(newy, newx), dist + 1));

      if (0 < board[newy][newx] && board[newy][newx] < shark.size) {
        Fish newfish = {newy, newx, dist + 1};
        fishes.push_back(newfish);
      }
    }
  }
}

void printboard() {
  printf("\n\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == n - 1) {
        printf("%d\n", board[i][j]);
      } else {
        printf("%d ", board[i][j]);
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &board[i][j]);
      if (board[i][j] == 9) {
        shark.y = i;
        shark.x = j;
        shark.size = 2;
        shark.eats = 0;
        shark.time = 0;
      }
    }
  }

  while (true) {
    fishes.clear();
    bfs(shark.y, shark.x);
    if (fishes.size() == 0) {
      printf("%d\n", shark.time);
      return 0;
    } else {
      sort(fishes.begin(), fishes.end(), comp);
      board[fishes[0].y][fishes[0].x] = 9;
      board[shark.y][shark.x] = 0;
      shark.y = fishes[0].y;
      shark.x = fishes[0].x;
      shark.eats++;
      shark.time += fishes[0].distance;
      if (shark.eats == shark.size) {
        shark.size++;
        shark.eats = 0;
      }
    }
    // printboard();
  }
}