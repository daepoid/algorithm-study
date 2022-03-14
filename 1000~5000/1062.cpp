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
int n, k, answer = 0;
string str;
bool alpha[26];
vector<string> v;

int readable() {
  int cnt = 0;
  bool flag;
  for (int i = 0; i < v.size(); i++) {
    flag = false;
    for (int j = 0; j < v[i].length(); j++) {
      if (!alpha[v[i][j] - 'a']) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      cnt++;
    }
  }
  return cnt;
}

void dfs(int idx, int cnt) {
  if (cnt == k) {
    answer = max(answer, readable());
    return;
  }
  for (int i = idx; i < 26; i++) {
    if (!alpha[i]) {
      alpha[i] = true;
      dfs(i, cnt + 1);
      alpha[i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> str;
    str.erase(str.begin(), str.begin() + 4);
    str.erase(str.end() - 4, str.end());
    v.push_back(str);
  }
  k -= 5;
  alpha['a' - 'a'] = true;
  alpha['n' - 'a'] = true;
  alpha['t' - 'a'] = true;
  alpha['i' - 'a'] = true;
  alpha['c' - 'a'] = true;

  dfs(0, 0);
  cout << answer << "\n";
}