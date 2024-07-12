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

int arr[10000001];

int main() {
  int n;
  scanf("%d", &n);
  arr[0] = 1;
  arr[1] = 1;
  arr[2] = 2;
  for (int i = 3; i <= n; i++) {
    arr[i] = (arr[i - 1] + arr[i - 2]) % 10;
  }
  printf("%d", arr[n] % 10);
}