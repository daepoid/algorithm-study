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
  int t;
  int arr[111][111];
  scanf("%d", &t);
  while (t-- > 0) {
    int m, n, cnt = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &arr[i][j]);
      }
    }
    for (int j = 0; j < n; j++) {
      for (int i = m - 1; i >= 0; i--) {
        for (int k = i - 1; k >= 0; k--) {
          if (arr[i][j] == 1) {
            break;
          } else {
            if (arr[k][j] == 1) {
              cnt += (i - k);
              swap(arr[i][j], arr[k][j]);
              break;
            }
          }
        }
      }
    }
    printf("%d\n", cnt);
  }
}