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
  int n, m, temp, result = 0;
  vector<int> v;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    v.push_back(temp);
  }
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        if (v[i] + v[j] + v[k] <= m && (v[i] + v[j] + v[k]) > result) {
          result = v[i] + v[j] + v[k];
        }
      }
    }
  }
  printf("%d\n", result);
}
