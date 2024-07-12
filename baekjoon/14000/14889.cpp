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

int main() {
  int board[20][20];
  int ans = 2147483647, n, s_sum, l_sum;
  vector<bool> v;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (i < n / 2) {
      v.push_back(false);
    } else {
      v.push_back(true);
    }
  }
  do {
    vector<int> team_s, team_l;
    for (int i = 0; i < n; i++) {
      if (v[i]) {
        team_s.push_back(i);
      } else {
        team_l.push_back(i);
      }
    }
    s_sum = 0;
    l_sum = 0;
    for (int i = 0; i < team_s.size() - 1; i++) {
      for (int j = i + 1; j < team_s.size(); j++) {
        s_sum += board[team_s[i]][team_s[j]] + board[team_s[j]][team_s[i]];
      }
    }
    for (int i = 0; i < team_l.size() - 1; i++) {
      for (int j = i + 1; j < team_l.size(); j++) {
        l_sum += board[team_l[i]][team_l[j]] + board[team_l[j]][team_l[i]];
      }
    }
    ans = min(ans, abs(s_sum - l_sum));
    if (ans == 0) {
      break;
    }
  } while (next_permutation(v.begin(), v.end()));
  printf("%d\n", ans);
}