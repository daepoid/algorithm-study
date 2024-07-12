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
  int t;
  scanf("%d", &t);
  while (t-- > 0) {
    vector<int> v;
    int n;
    char mod;
    scanf("%d %c", &n, &mod);
    if (mod == 'C') {
      char temp;
      scanf("%c", &temp);
      for (int i = 0; i < n; i++) {
        scanf("%s", &temp);
        v.push_back(temp - 'A' + 1);
      }
      for (int i = 0; i < n; i++) {
        if (i == n - 1) {
          printf("%d\n", v[i]);
        } else {
          printf("%d ", v[i]);
        }
      }
    } else if (mod == 'N') {
      int temp;
      scanf("%c", &temp);

      for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        v.push_back(temp + 'A' - 1);
      }
      for (int i = 0; i < n; i++) {
        if (i == n - 1) {
          printf("%c\n", v[i]);
        } else {
          printf("%c ", v[i]);
        }
      }
    }
  }
}