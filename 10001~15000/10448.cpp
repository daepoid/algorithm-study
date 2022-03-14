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
#define MAX_SIZE 45
int arr[MAX_SIZE];
bool chk[1000];

int main() {
  for (int i = 0; i < MAX_SIZE; i++) {
    arr[i] = i * (i + 1) / 2;
  }

  for (int i = 1; i < MAX_SIZE; i++) {
    for (int j = 1; j < MAX_SIZE; j++) {
      for (int k = 1; k < MAX_SIZE; k++) {
        if (arr[i] + arr[j] + arr[k] <= 1000) {
          chk[arr[i] + arr[j] + arr[k]] = true;
        }
      }
    }
  }

  int t;
  scanf("%d", &t);
  while (t-- > 0) {
    int n;
    scanf("%d", &n);
    if (chk[n]) {
      printf("1\n");
    } else {
      printf("0\n");
    }
  }
}