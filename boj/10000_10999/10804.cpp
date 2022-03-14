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
  int arr[20];
  for (int i = 0; i < 20; i++) {
    arr[i] = i + 1;
  }
  for (int i = 0; i < 10; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    reverse(arr + a - 1, arr + b);
  }
  for (int i = 0; i < 19; i++) {
    printf("%d ", arr[i]);
  }
  printf("%d\n", arr[19]);
}