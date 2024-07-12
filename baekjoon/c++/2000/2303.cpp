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

int n;
int arr[1000][5];
int arr_max[1000];
int total_max = 0, total_max_idx = -1;

int main() {

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = j + 1; k < 4; k++) {
        for (int l = k + 1; l < 5; l++) {
          if (arr_max[i] < (arr[i][j] + arr[i][k] + arr[i][l]) % 10) {
            arr_max[i] = (arr[i][j] + arr[i][k] + arr[i][l]) % 10;
          }
        }
      }
    }
    if (total_max <= arr_max[i]) {
      total_max = arr_max[i];
      total_max_idx = i;
    }
  }
  printf("%d\n", total_max_idx + 1);
}