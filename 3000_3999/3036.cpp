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

int gcd(int a, int b) {
  int n;
  if (a < b) {
    swap(a, b);
  }
  while (b != 0) {
    n = a % b;
    a = b;
    b = n;
  }
  return a;
}

int main() {
  int n, num;
  int arr[100];
  scanf("%d", &n);
  scanf("%d", &arr[0]);
  for (int i = 1; i < n; i++) {
    scanf("%d", &arr[i]);
    int temp = gcd(arr[0], arr[i]);
    printf("%d/%d\n", arr[0] / temp, arr[i] / temp);
  }
}