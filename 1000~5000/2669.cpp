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

bool board[101][101];

int main() {
  int a, b, c, d, cnt = 0;
  for (int i = 0; i < 4; i++) {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    for (int i = b; i < d; i++) {
      for (int j = a; j < c; j++) {
        board[i][j] = true;
      }
    }
  }
  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) {
      if (board[i][j]) {
        cnt++;
      }
    }
  }
  printf("%d\n", cnt);
}