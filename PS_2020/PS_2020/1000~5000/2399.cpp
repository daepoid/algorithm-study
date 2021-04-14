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
  int n;
  long long int temp, ans = 0;
  vector<long long int> v;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &temp);
    v.push_back(temp);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans += abs(v[i] - v[j]);
    }
  }
  printf("%lld\n", ans);
}