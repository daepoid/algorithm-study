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
int arr[1000][1000];

int posx[4] = {0, 1, 0, -1};
int posy[4] = {-1, 0, 1, 0};

int main() {
  int n, x, a = 1, b = 1, num = 1;
  scanf("%d", &n);
  scanf("%d", &x);
  int k = 0, l = -1, pos = -1;
  bool flag = true;
  for (int i = n / 2, j = n / 2; i >= 0 && j >= 0; i += b, j += a) {
    arr[i][j] = num++;
    l++;
    if (flag && k == l) {
      k++;
      l = 0;
      pos = (pos + 1) % 4;
      a = posx[pos];
      b = posy[pos];
      flag = false;
    } else if (!flag && k == l) {
      flag = true;
      l = 0;
      pos = (pos + 1) % 4;
      a = posx[pos];
      b = posy[pos];
    }
  }
  int ans1, ans2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == x) {
        ans1 = i + 1;
        ans2 = j + 1;
      }
      if (j == n - 1) {
        printf("%d\n", arr[i][j]);
      } else {
        printf("%d ", arr[i][j]);
      }
    }
  }
  printf("%d %d\n", ans1, ans2);
}