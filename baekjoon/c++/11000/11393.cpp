#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, m, i, j;
  bool flag = true;
  char arr[11][11];
  char newarr[22][22];
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%s", arr[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      newarr[i][j * 2] = arr[i][j];
      newarr[i][j * 2 + 1] = arr[i][j];
    }
    newarr[i][j * 2] = '\0';
  }
  for (i = 0; i < n; i++) {
    char newstr[22];
    scanf("%s", newstr);
    if (strcmp(newarr[i], newstr) != 0) {
      flag = false;
    }
  }
  if (!flag) {
    printf("Not Eyfa\n");
  } else {
    printf("Eyfa\n");
  }
}