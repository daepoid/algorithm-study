#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  while (true) {
    int n, p;
    int arr[3];
    scanf("%d %d", &n, &p);
    if (n == 0) {
      break;
    }

    if (p % 2 == 1) {
      arr[0] = p + 1;
    } else {
      arr[0] = p - 1;
      p--;
    }
    arr[1] = n - p;
    arr[2] = n - p + 1;
    sort(arr, arr + 3);
    printf("%d %d %d\n", arr[0], arr[1], arr[2]);
  }
}