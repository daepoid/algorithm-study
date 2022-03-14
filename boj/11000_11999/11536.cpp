#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  string temp1, temp2;
  int flag = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> temp1;
    if (i > 0 && temp1.compare(temp2) > 0) {
      flag++;
    } else if (i > 0 && temp1.compare(temp2) < 0) {
      flag--;
    }
    temp2 = temp1;
  }
  if (flag == n - 1) {
    printf("INCREASING\n");
  } else if (flag == 1 - n) {
    printf("DECREASING\n");
  } else {
    printf("NEITHER\n");
  }
}