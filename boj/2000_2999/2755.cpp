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
  int n, point, point_sum = 0;
  string name, score;
  double total = 0, temp = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> name >> point >> score;
    point_sum += point;
    if (score[0] == 'A') {
      if (score[1] == '+') {
        total += 4.3 * point;
      } else if (score[1] == '0') {
        total += 4.0 * point;
      } else if (score[1] == '-') {
        total += 3.7 * point;
      }
    } else if (score[0] == 'B') {
      if (score[1] == '+') {
        total += 3.3 * point;
      } else if (score[1] == '0') {
        total += 3.0 * point;
      } else if (score[1] == '-') {
        total += 2.7 * point;
      }
    } else if (score[0] == 'C') {
      if (score[1] == '+') {
        total += 2.3 * point;
      } else if (score[1] == '0') {
        total += 2.0 * point;
      } else if (score[1] == '-') {
        total += 1.7 * point;
      }
    } else if (score[0] == 'D') {
      if (score[1] == '+') {
        total += 1.3 * point;
      } else if (score[1] == '0') {
        total += 1.0 * point;
      } else if (score[1] == '-') {
        total += 0.7 * point;
      }
    } else if (score[0] == 'F') {
      total += 0.0;
    }
  }
  printf("%.2lf\n", total / point_sum + 0.000000001);
}