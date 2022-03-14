#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n;
  scanf("%d", &t);
  while (t-- > 0) {
    scanf("%d", &n);
    vector<pair<int, int>> v;
    int a, b, answer = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &a, &b);
      v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    answer = 1;
    int temp = v[0].second;
    for (int i = 1; i < n; i++) {
      if (v[i].second < temp) {
        temp = v[i].second;
        answer++;
      }
    }
    printf("%d\n", answer);
  }
}