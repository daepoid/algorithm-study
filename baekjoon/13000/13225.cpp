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
  int n, num, cnt, temp;
  bool flag;
  vector<int> arr;
  for (int i = 2; i < 10001; i++) {
    flag = true;
    for (int j = 2; j < i; j++) {
      if (i % j == 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      arr.push_back(i);
    }
  }

  scanf("%d", &n);
  while (n-- > 0) {
    int sum = 1;
    vector<int> ans;
    scanf("%d", &num);
    printf("%d ", num);
    for (int i = 0; arr[i] <= num; i++) {
      ans.push_back(0);
      while (num % arr[i] == 0) {
        ans[i]++;
        num /= arr[i];
      }
    }
    for (int i = 0; i < ans.size(); i++) {
      sum *= ans[i] + 1;
    }
    printf("%d\n", sum);
  }
}