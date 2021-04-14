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

bool compare(string a, string b) {
  int sum_a = 0, sum_b = 0;
  if (a.length() < b.length()) {
    return true;
  } else if (a.length() > b.length()) {
    return false;
  } else {
    for (int i = 0; i < a.length(); i++) {
      if (isdigit(a[i])) {
        sum_a += (a[i] - '0');
      }
    }
    for (int i = 0; i < b.length(); i++) {
      if (isdigit(b[i])) {
        sum_b += (b[i] - '0');
      }
    }
    if (sum_a < sum_b) {
      return true;
    } else if (sum_a > sum_b) {
      return false;
    } else {
      for (int i = 0; i < a.length(); i++) {
        if (isdigit(a[i]) && !isdigit(b[i])) {
          return true;
        } else if (!isdigit(a[i]) && isdigit(b[i])) {
          return false;
        } else if (a[i] == b[i]) {
          continue;
        } else {
          return a[i] < b[i];
        }
      }
      return true;
    }
  }
}

int main() {
  int n;
  vector<string> arr;
  string str;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> str;
    arr.push_back(str);
  }
  sort(arr.begin(), arr.end(), compare);
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << endl;
  }
}
