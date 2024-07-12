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
  double A[7] = {9.23076,  1.84523, 56.0211, 4.99087,
                 0.188807, 15.9803, 0.11193};
  double B[7] = {26.7, 75, 1.5, 42.5, 210, 3.8, 254};
  double C[7] = {1.835, 1.348, 1.05, 1.81, 1.41, 1.04, 1.88};
  bool D[7] = {true, false, false, true, false, false, true};
  int t;
  scanf("%d", &t);
  while (t-- > 0) {
    int P[7];
    int total = 0;
    for (int i = 0; i < 7; i++) {
      scanf("%d", &P[i]);
      if (D[i]) {
        total += int(A[i] * pow((B[i] - P[i]), C[i]));
      } else {
        total += int(A[i] * pow((P[i] - B[i]), C[i]));
      }
    }
    printf("%d\n", total);
  }
}