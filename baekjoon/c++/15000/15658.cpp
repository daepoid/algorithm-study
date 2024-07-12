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

int n, temp, sum, arr[100];
int max_num = -2100000000;
int min_num = 2100000000;
vector<int> op;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < 4; i++) {
    scanf("%d", &temp);
    for (int j = 0; j < temp; j++) {
      op.push_back(i);
    }
  }
  do {
    sum = arr[0];
    for (int i = 0; i < n - 1; i++) {
      if (op[i] == 0) {
        sum += arr[i + 1];
      } else if (op[i] == 1) {
        sum -= arr[i + 1];
      } else if (op[i] == 2) {
        sum *= arr[i + 1];
      } else if (op[i] == 3) {
        if (sum < 0) {
          sum *= -1;
          sum /= arr[i + 1];
          sum *= -1;
        } else {
          sum /= arr[i + 1];
        }
      }
    }
    min_num = min(min_num, sum);
    max_num = max(max_num, sum);
  } while (next_permutation(op.begin(), op.end()));
  printf("%d\n%d\n", max_num, min_num);
}