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
  int t, n, cnt;
  string ans, str;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    cnt = 0;
    scanf("%d", &n);
    cin >> str >> ans;
    for (int j = 0; j < n; j++) {
      if (str[j] != ans[j]) {
        cnt++;
      }
    }
    printf("Case %d: %d\n", i, cnt);
  }
}