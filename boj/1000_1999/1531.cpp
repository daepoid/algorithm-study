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

int arr[111][111];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int ax, ay, bx, by;
    scanf("%d %d %d %d", &ax, &ay, &bx, &by);
    for (int a = ax; a <= bx; a++) {
      for (int b = ay; b <= by; b++) {
        arr[a][b]++;
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) {
      if (arr[i][j] > m) {
        cnt++;
      }
    }
  }
  printf("%d\n", cnt);
}