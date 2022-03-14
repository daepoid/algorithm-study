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

bool search_num(vector<int> arr, int low, int high, int temp) {
  if (low > high) {
    return false;
  }
  int mid = (low + high) / 2;
  if (arr[mid] == temp) {
    return true;
  } else if (arr[mid] > temp) {
    return search_num(arr, low, mid - 1, temp);
  } else {
    return search_num(arr, mid + 1, high, temp);
  }
}

int main() {
  int t, n, m, temp;
  scanf("%d", &t);
  while (t-- > 0) {
    vector<int> arr;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &temp);
      arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      scanf("%d", &temp);
      if (search_num(arr, 0, arr.size(), temp)) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    }
  }
}