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

bool board[100][100];
int main() {
  int n, cnt = 0;
  scanf("%d", &n);
  while (n-- > 0) {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = b; i < b + 10; i++) {
      for (int j = a; j < a + 10; j++) {
        board[i][j] = true;
      }
    }
  }
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (board[i][j]) {
        cnt++;
      }
    }
  }
  printf("%d\n", cnt);
}