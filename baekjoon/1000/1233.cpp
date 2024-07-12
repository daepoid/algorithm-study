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

int arr[100];

int main() {
  int a, b, c, max = 0;
  scanf("%d %d %d", &a, &b, &c);
  for (int i = 1; i < a + 1; i++) {
    for (int j = 1; j < b + 1; j++) {
      for (int k = 1; k < c + 1; k++) {
        arr[i + j + k]++;
      }
    }
  }
  for (int i = 3; i < 100; i++) {
    if (arr[max] < arr[i]) {
      max = i;
    }
  }
  printf("%d\n", max);
}