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
  int n, m, num, max_point = 0;
  vector<vector<int>> arr;
  scanf("%d %d", &n, &m);
  vector<int> point(n);
  for (int i = 0; i < n; i++) {
    vector<int> temp;
    for (int j = 0; j < m; j++) {
      scanf("%d", &num);
      temp.push_back(num);
    }
    sort(temp.begin(), temp.end(), greater<int>());
    arr.push_back(temp);
  }
  for (int i = 0; i < m; i++) {
    int max = 0;
    for (int j = 0; j < n; j++) {
      if (max < arr[j][i]) {
        max = arr[j][i];
      }
    }
    for (int j = 0; j < n; j++) {
      if (max == arr[j][i]) {
        point[j]++;
        if (max_point < point[j]) {
          max_point = point[j];
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (point[i] == max_point) {
      printf("%d ", i + 1);
    }
  }
}