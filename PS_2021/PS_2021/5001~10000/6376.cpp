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
  int arr[10];
  arr[0] = 1;
  double sum = 0;
  for (int i = 1; i < 10; i++) {
    arr[i] = arr[i - 1] * i;
  }
  printf("n e\n- -----------\n");
  printf("0 1\n1 2\n2 2.5\n3 2.666666667\n4 2.708333333\n");
  for (int i = 0; i < 10; i++) {
    sum += 1 / (double)arr[i];
    if (i > 4) {
      printf("%d %.9lf\n", i, sum);
    }
  }
}