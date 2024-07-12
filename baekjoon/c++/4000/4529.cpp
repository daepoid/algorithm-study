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
  int n, temp;
  vector<int> v;
  while (true) {
    v.clear();
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &temp);
      if (i > 0 && temp != v[v.size() - 1]) {
        v.push_back(temp);
      } else if (i == 0) {
        v.push_back(temp);
      }
    }
    for (int i = 0; i < v.size(); i++) {
      printf("%d ", v[i]);
    }
    printf("$\n");
  }
}