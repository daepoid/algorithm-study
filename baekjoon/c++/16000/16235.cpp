#include <bits/stdc++.h>
#define MAX 11
using namespace std;

int n, m, k;
int board[MAX][MAX], A[MAX][MAX], temp_board[MAX][MAX];
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
vector<int> trees[MAX][MAX];

bool isvalid(int newy, int newx) {
  return 0 < newy && newy <= n && 0 < newx && newx <= n;
}

void spring_summer() {
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (trees[i][j].size() == 0) {
        continue;
      }
      vector<int> temp;
      int dead = 0;
      sort(trees[i][j].begin(), trees[i][j].end());
      for (int k = 0; k < trees[i][j].size(); k++) {
        if (board[i][j] >= trees[i][j][k]) {
          board[i][j] -= trees[i][j][k];
          temp.push_back(trees[i][j][k] + 1);
        } else {
          dead += (trees[i][j][k] / 2);
        }
      }
      trees[i][j] = temp;
      board[i][j] += dead;
    }
  }
}

void fall() {
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (trees[i][j].size() == 0) {
        continue;
      }
      for (int k = 0; k < trees[i][j].size(); k++) {
        if (trees[i][j][k] % 5 == 0) {
          for (int l = 0; l < 8; l++) {
            int newy = i + dy[l];
            int newx = j + dx[l];
            if (isvalid(newy, newx)) {
              trees[newy][newx].push_back(1);
            }
          }
        }
      }
    }
  }
}

void winter() {
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      board[i][j] += A[i][j];
    }
  }
}

int main() {
  int x, y, z, answer = 0;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      board[i][j] = 5;
      scanf("%d", &A[i][j]);
    }
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &y, &x, &z);
    trees[y][x].push_back(z);
  }

  for (int i = 0; i < k; i++) {
    spring_summer();
    fall();
    winter();
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      answer += trees[i][j].size();
    }
  }
  printf("%d\n", answer);
}