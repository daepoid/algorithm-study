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

bool chk[1000000];

int main() {
  int t, k, n, cnt;
  char cmd[5];
  scanf("%d", &t);
  while (t-- > 0) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>
        maxheap;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        minheap;
    memset(chk, false, sizeof(chk));
    scanf("%d", &k);
    cnt = 0;
    for (int i = 0; i < k; i++) {
      scanf("%s %d", cmd, &n);
      if (cmd[0] == 'I') {
        maxheap.push(make_pair(n, i));
        minheap.push(make_pair(n, i));
        chk[i] = true;
        cnt++;
      } else {
        if (n == 1 && cnt > 0) {
          while (!chk[maxheap.top().second] && !maxheap.empty()) {
            maxheap.pop();
          }
          chk[maxheap.top().second] = false;
          maxheap.pop();
          cnt--;
        } else if (n == -1 && cnt > 0) {
          while (!chk[minheap.top().second] && !minheap.empty()) {
            minheap.pop();
          }
          chk[minheap.top().second] = false;
          minheap.pop();
          cnt--;
        }
      }
    }
    while (!chk[maxheap.top().second] && !maxheap.empty()) {
      maxheap.pop();
    }
    while (!chk[minheap.top().second] && !minheap.empty()) {
      minheap.pop();
    }
    if (maxheap.empty()) {
      printf("EMPTY\n");
    } else {
      printf("%d %d\n", maxheap.top().first, minheap.top().first);
    }
  }
}