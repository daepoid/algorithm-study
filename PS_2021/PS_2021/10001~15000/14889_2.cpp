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

int n, board[22][22], min_val = 2100000000;
vector<int> check;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  for (int i = 0; i < n / 2; i++) {
    check.push_back(1);
    check.push_back(0);
  }
  sort(check.begin(), check.end());
  do {
    vector<int> left, right;
    int left_sum = 0, right_sum = 0;
    for (int i = 0; i < check.size(); i++) {
      if (check[i] == 1) {
        left.push_back(i);
      } else if (check[i] == 0) {
        right.push_back(i);
      }
    }
    for (int i = 0; i < n / 2 - 1; i++) {
      for (int j = i + 1; j < n / 2; j++) {
        left_sum += board[left[i]][left[j]];
        left_sum += board[left[j]][left[i]];
        right_sum += board[right[i]][right[j]];
        right_sum += board[right[j]][right[i]];
      }
    }
    min_val = min(min_val, abs(right_sum - left_sum));
  } while (next_permutation(check.begin(), check.end()));
  printf("%d\n", min_val);
}