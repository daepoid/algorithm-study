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
  int A[10], B[10], temp;
  bool flag, before_win;
  A[0] = 0;
  B[0] = 0;
  for (int i = 1; i < 10; i++) {
    scanf("%d", &temp);
    A[i] = A[i - 1] + temp;
  }
  for (int i = 1; i < 10; i++) {
    scanf("%d", &temp);
    B[i] = B[i - 1] + temp;
    if (A[i] > B[i - 1]) {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
}