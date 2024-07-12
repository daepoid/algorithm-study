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

vector<char> v;
vector<bool> b;

bool check() {
  int cnt = 0, cnt2 = 0;
  for (int i = 0; i < b.size(); i++) {
    if (b[i] && (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' ||
                 v[i] == 'u')) {
      cnt2++;
    } else if (b[i]) {
      cnt++;
    }
  }
  if (cnt >= 2 && cnt2 >= 1) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int l, c;
  char temp[4];
  scanf("%d %d", &l, &c);
  for (int i = 0; i < c; i++) {
    scanf("%s", temp);
    v.push_back(temp[0]);
  }
  for (int i = 0; i < l; i++) {
    b.push_back(true);
  }
  for (int i = 0; i < c - l; i++) {
    b.push_back(false);
  }
  sort(v.begin(), v.end());
  do {
    if (check()) {
      for (int i = 0; i < c; i++) {
        if (b[i]) {
          printf("%c", v[i]);
        }
      }
      printf("\n");
    }
  } while (prev_permutation(b.begin(), b.end()));
}