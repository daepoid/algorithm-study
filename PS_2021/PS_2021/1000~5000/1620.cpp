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
  //   ios_base::sync_with_stdio(false);
  //   cin.tie(NULL);
  //   cout.tie(NULL);

  int n, m;
  char str[21];
  map<string, int> board;
  vector<string> v;

  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    board.insert(make_pair(str, i + 1));
    v.push_back(str);
  }
  for (int i = 0; i < m; i++) {
    scanf("%s", str);
    if (isdigit(str[0])) {
      cout << v[stoi(str) - 1] << "\n";
    } else {
      printf("%d\n", board[str]);
    }
  }
}