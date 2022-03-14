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
  bool arr[3] = {true, false, false};
  string str;
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'A') {
      swap(arr[0], arr[1]);
    } else if (str[i] == 'B') {
      swap(arr[1], arr[2]);
    } else if (str[i] == 'C') {
      swap(arr[0], arr[2]);
    }
  }
  for (int i = 0; i < 3; i++) {
    if (arr[i]) {
      printf("%d\n", i + 1);
    }
  }
}