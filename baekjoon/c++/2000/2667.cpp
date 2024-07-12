#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

char board[30][30];
bool visited[30][30];
vector<int> ans;
int n, cnt;
char temp[30];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool isvalid(int i, int j) { return 0 <= i && i < n && 0 <= j && j < n; }

void dfs(int i, int j) {
  visited[i][j] = true;
  cnt++;
  for (int k = 0; k < 4; k++) {
    int newy = i + dy[k];
    int newx = j + dx[k];
    if (isvalid(newx, newy) && board[newy][newx] == '1' &&
        !visited[newy][newx]) {
      dfs(newy, newx);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", board[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == '1' && !visited[i][j]) {
        cnt = 0;
        dfs(i, j);
        ans.push_back(cnt);
      }
    }
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d\n", ans[i]);
  }
}