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
  int n, m, cnt = 0;
  scanf("%d %d", &n, &m);
  vector<int> mazino;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    vector<int> temp;
    int num;
    for (int j = 0; j < a; j++) {
      scanf("%d", &num);
      temp.push_back(num);
    }
    sort(temp.begin(), temp.end());
    if (temp.size() < b) {
      mazino.push_back(1);
    } else {
      mazino.push_back(temp[temp.size() - b]);
    }
  }
  sort(mazino.begin(), mazino.end());
  for (int i = 0; i < mazino.size(); i++) {
    m -= mazino[i];
    if (m >= 0) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
}