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

int board[110][110];
int arr[110];

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 0; k < t; k++) {
    int a, b, c, d, cnt = 0;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    for (int i = b; i < b + d; i++) {
      for (int j = a; j < a + c; j++) {
        board[i][j] = k + 1;
      }
    }
  }
  for (int i = 0; i < 110; i++) {
    for (int j = 0; j < 110; j++) {
      arr[board[i][j]]++;
    }
  }
  for (int i = 0; i < t; i++) {
    printf("%d\n", arr[i + 1]);
  }
}