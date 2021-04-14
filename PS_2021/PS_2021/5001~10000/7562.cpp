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

int tc, l, a, b, desa, desb;
int da[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int db[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dp[333][333];

queue<pair<int, int>> q, newq;

bool isvalid(int newa, int newb) {
  return 0 <= newa && newa < l && 0 <= newb && newb < l;
}

void bfs() {
  while (!q.empty()) {
    a = q.front().first;
    b = q.front().second;
    q.pop();
    for (int k = 0; k < 8; k++) {
      int newa = a + da[k];
      int newb = b + db[k];
      if (dp[newa][newb] == 0 && isvalid(newa, newb)) {
        dp[newa][newb] = dp[a][b] + 1;
        q.push(make_pair(newa, newb));
      }
    }
  }
}

int main() {
  scanf("%d", &tc);
  while (tc-- > 0) {
    q = newq;
    scanf("%d", &l);
    scanf("%d %d", &a, &b);
    scanf("%d %d", &desa, &desb);
    memset(dp, 0, sizeof(dp));
    dp[a][b] = 1;
    q.push(make_pair(a, b));
    bfs();
    printf("%d\n", dp[desa][desb] - 1);
  }
}