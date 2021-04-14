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
  int n, temp;
  int arr[13];
  while (true) {
    scanf("%d", &n);
    if (n == 0) {
      return 0;
    }
    vector<int> v;
    vector<int> comb;
    for (int i = 0; i < n; i++) {
      scanf("%d", &temp);
      v.push_back(temp);
      if (i < 6) {
        comb.push_back(1);
      } else {
        comb.push_back(0);
      }
    }
    sort(comb.begin(), comb.end(), greater<int>());
    do {
      for (int i = 0; i < n; i++) {
        if (comb[i] == 1) {
          printf("%d ", v[i]);
        }
      }
      printf("\n");
    } while (prev_permutation(comb.begin(), comb.end()));
    
      printf("\n");
  }
}