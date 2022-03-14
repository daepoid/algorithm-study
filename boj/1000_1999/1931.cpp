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

struct time {
  int start;
  int end;
};

bool cmp(time a, time b) {
  if (a.end == b.end) {
    return a.start < b.start;
  } else {
    return a.end < b.end;
  }
}

int main() {
  int n, a, b, cnt = 0, last = 0;
  scanf("%d", &n);
  vector<time> arr;
  for (int i = 0; i < n; i++) {
    time temp;
    scanf("%d %d", &temp.start, &temp.end);
    arr.push_back(temp);
  }
  sort(arr.begin(), arr.end(), cmp);
  for (int i = 0; i < arr.size(); i++) {
    if (last <= arr[i].start) {
      last = arr[i].end;
      cnt++;
    }
  }
  printf("%d\n", cnt);
}